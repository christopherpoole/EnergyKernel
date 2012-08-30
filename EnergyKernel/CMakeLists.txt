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


cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(EnergyKernel)

# GEANT4 core
find_package(Geant4 REQUIRED ui_all vis_all)
include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(/usr/include/python2.7)
include_directories(/usr/local/lib/python2.7/dist-packages/PyUblas-2011.1-py2.7-linux-x86_64.egg/include)

# User code
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

SET(LIBRARY_OUTPUT_PATH "..")
add_library(EnergyKernel "SHARED" LIB_Energy_Kernel.cc ${sources} ${headers})

target_link_libraries(EnergyKernel ${Geant4_LIBRARIES})
target_link_libraries(EnergyKernel /usr/lib/libboost_python.so)
target_link_libraries(EnergyKernel /usr/lib/libpython2.7.so)

