# mu-data-products

A C++ library defining the persistent data products (stored as ROOT TObjects) used when unpacking midas data.

## Requirements

- [CMake]
- [ROOT]

## Cloning the repository

You can either clone this repository on its own via:

```bash
git clone https://github.com/PIONEER-Experiment/mu-data-products.git
``` 

or you can clone the app level repository. If you want to clone the app level repository, follow the instructions here: https://github.com/PIONEER-Experiment/mu-app. If you are here for analysis, you can clone this repository directly. You probably also want to clone the [mu-notebooks](https://github.com/PIONEER-Experiment/mu-notebooks) repository for a place to store your analysis notebooks. It also contains examples, plotting helper functions, etc..

## Build instructions

If you are building this repository on its own, you should first source the `setenv.sh` script to set up the environment, and then you can build:

```bash
source ./scripts/setenv.sh
./scripts/build.sh -o
```

## Running the application

Building the application will create ROOT dictionaries that define the data products produced when we unpack the raw midas data. No executable is created. 

These data products are accessible in a ROOT macro or a Jupyter notebook using pyROOT. The `script/setenv.sh` script will set up the environment so that the ROOT dictionaries are available in your ROOT session. For a Jupyter notebook, you'll need to load the libraries with something like:
```python
import ROOT
ROOT.gSystem.Load("/PATH/TO/PROJECT/mu-data-products/install/lib/libdata_products.dylib")
```
The `.dylib` is appropriate for macOS; on Linux, it will be `.so`. See the [mu-notebooks](https://github.com/PIONEER-Experiment/mu-notebooks) repository for some example jupyter notebooks.