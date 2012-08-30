# License & Copyright
# ===================
#
# Copyright 2012 Christopher M Poole <mail@christopherpoole.net>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.


import pyublas

import pylab
import numpy

import Geant4
import EnergyKernel


if __name__ == "__main__":
    detector_construction = EnergyKernel.DetectorConstruction()
    Geant4.gRunManager.SetUserInitialization(detector_construction)

    physics_list = EnergyKernel.PhysicsList()
    Geant4.gRunManager.SetUserInitialization(physics_list)

    primary_generator = EnergyKernel.PrimaryGeneratorAction()
    Geant4.gRunManager.SetUserAction(primary_generator)

    event_action = EnergyKernel.EventAction()
    Geant4.gRunManager.SetUserAction(event_action)

    stepping_action = EnergyKernel.SteppingAction()
    Geant4.gRunManager.SetUserAction(stepping_action)

    Geant4.gRunManager.Initialize()
    Geant4.gRunManager.BeamOn(int(1e4))
    
    energy = detector_construction.GetEnergyHistogram()
    counts = detector_construction.GetCountsHistogram()

    pylab.matshow(numpy.log(energy[50,:,:]))
    pylab.show()

