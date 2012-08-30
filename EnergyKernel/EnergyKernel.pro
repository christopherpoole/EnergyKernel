SOURCES += \
    src/PrimaryGeneratorAction.cc \
    src/DetectorConstruction.cc \
    src/PhysicsList.cc \
    src/SteppingAction.cc \
    LIB_Energy_Kernel.cc \
    src/SensitiveDetector.cc \
    src/EventAction.cc

HEADERS += \
    include/PrimaryGeneratorAction.hh \
    include/PhysicsList.hh \
    include/DetectorConstruction.hh \
    include/SteppingAction.hh \
    include/SensitiveDetector.hh \
    include/EventAction.hh

INCLUDEPATH += /opt/cern/geant4.9.5/include/Geant4
INCLUDEPATH += /usr/local/lib/python2.7/dist-packages/PyUblas-2011.1-py2.7-linux-x86_64.egg/include/

