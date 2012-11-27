Energy or scatter kernels are an integral part of analytical radiotherapy dose calculation techniques; convolve the scatter kernel with TERMA, and you get dose.
This GEANT4 simulation provides a generic starting point for the calculation of scatter kernels.
Energy and particle type can be set in the `PrimaryGeneratorAction`.
Energy is accumulated in numpy arrays, parsed to the sensitive detector with the help of [pyublas](http://mathema.tician.de/software/pyublas).

## Compilation
    git clone 
    cd EnergyKernel/EnergyKernel
    mkdir build
    cd build
    cmake ..
    make

## Usage
From the top level directory run

    python example.py

# Dependencies

Make sure you have GEANT4 as well as the Python wrapper installed.
You will also need the following Python modules:
* [pyublas](http://mathema.tician.de/software/pyublas)
* numpy
* pylab/matplotlib

