//////////////////////////////////////////////////////////////////////////
// License & Copyright
// ===================
// 
// Copyright 2012 Christopher M Poole <mail@christopherpoole.net>
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//////////////////////////////////////////////////////////////////////////


#ifndef DetectorConstruction_H
#define DetectorConstruction_H 1


// GEANT4 //
#include "G4VUserDetectorConstruction.hh"

#include "G4Box.hh"
#include "G4Orb.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

#include "boost/python.hpp"
#include "pyublas/numpy.hpp"

#include "SensitiveDetector.hh"


class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    DetectorConstruction();
    ~DetectorConstruction();

    G4VPhysicalVolume* Construct();


    pyublas::numpy_vector<float> GetEnergyHistogram() {
        return detector->energy_histogram;
    }

    pyublas::numpy_vector<float> GetCountsHistogram() {
        return detector->counts_histogram;
    }

    void SetInteractionOrigin(G4ThreeVector origin) {
        this->interaction_origin = origin;
    }

    G4ThreeVector GetInteractionOrigin() {
        return this->interaction_origin;
    }

  private:
    SensitiveDetector* detector;
    G4ThreeVector interaction_origin;

    G4Orb* world_solid;
    G4LogicalVolume* world_logical;
    G4VPhysicalVolume* world_physical;

};
#endif

