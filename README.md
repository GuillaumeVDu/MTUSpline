# MTUSpline
C++ code for creating and using spline for musculo tendon unit kinematics (Moment arm and muscle-tendon length from joint angle)

## Dependencies

1. [BOOST](http://www.boost.org/users/download/) (Ubuntu command: sudo apt-get install libboost-dev) Tested version: 1.64.0 on Win10 and Win7./!\ 1.66 does not work.
1. [XSD V4](https://codesynthesis.com/products/xsd/download.xhtml) (Ubuntu command: sudo apt-get install xsdcxx)
1. [CMAKE](https://cmake.org/download/) (Ubuntu command: sudo apt-get install cmake) Tested version: 3.8.2 on Win10 and 3.10 on Win7. 3.14 and 3.12 does not work with OpenSim 3.1 (due to "$ENV{ProgramFiles(x86)}"). 
1. [OpenSim 3.3](https://simtk.org/frs/index.php?group_id=91) Not mandatory (for creating the spline coefficients). Tested on Win10.

## Test

A Test module is availible in the Test folder.

To use just run:
```
.\bin\Win\Debug\TestBoostBSpline.exe
```

In the windows powershell. The data used can be fond in cfg/SplineCoeff for the spline coefficients and in cfg/TestData for the data used by the testing modules.
The output should be:
```
Running 1 test case...

*** No errors detected
```
