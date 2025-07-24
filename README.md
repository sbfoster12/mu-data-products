# mu-data-products

A C++ library defining the persistent data products used when unpacking midas data.

## Requirements

- [CMake]
- [ROOT]

## Cloning the repository

You can either clone this repository on its own via:

```bash
git clone https://github.com/sbfoster12/mu-data-products.git
``` 

or you can clone the app level repository. Follow the instructions here: https://github.com/sbfoster12/mu-app

## Build instructions

If you are building this repository on its own, you should first source the `setenv.sh` script to set up the environment, and then you can build:

```bash
source ./scripts/setenv.sh
./scripts/build.sh
```

## Running the application

Building the application will create ROOT dictionaries that define the data products produced when we unpack the raw midas data. No executable is created. 

These data products are accesible in a ROOT macro or a jupter notebook using pyROOT. The `script/setenv.sh` script will set up the environment so the ROOT dictionaries are available in your ROOT session. For a jupyter notebook, you'll need to load the libraries with:
```python
import ROOT
ROOT.gSystem.Load("/PATH/TO/PROJECT/mu-data-products/install/lib/libdata_products.dylib")
```
The `.dylib` is appropriate for macOS; on Linux, it will be `.so`.