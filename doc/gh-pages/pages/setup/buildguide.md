---
title: Build from Source
parent: Setup
nav_order: 2
---
# Build from Source

## Get a compiler

Make sure you have one of the following compilers installed:

| Windows | Linux | MacOS |
|---------|-------|-------|
| min. MSVC 2015 (We recommend the [MSVC 2017 Community Version](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&rel=15&src=myvs) compiler) | min. [GCC 5.3.1](https://gcc.gnu.org/releases.html) | min. [Clang 3.5](https://developer.apple.com/xcode/)|

## Get Qt

### Download the Qt installer

Qt is the only dependency you will need to install. Go to the Qt download section and download the [Qt installer](https://www.qt.io/download-qt-installer?hsCtaTracking=9f6a2170-a938-42df-a8e2-a9f0b1d6cdce%7C6cb0de4f-9bb5-4778-ab02-bfb62735f3e5). 

### Install Qt

Please note that Qt 5.10.0 or higher is needed in order to have full Qt3D support. Install the Qt version with the minimum of the following features (uncheck all other boxes) to a path without white spaces:

- Qt/5.12.6/MSVC 2017 64-bit (Make sure to select the correct version based on your compiler)
- Qt/5.12.6/QtCharts

After the installation is finsihed make sure to add the Qt bin folder (e.g. `<QtFolder>\5.12.6\msvc2017_64\bin`) to your path variable. On Linux and MacOS you might also need to add the Qt lib folder (e.g. `<QtFolder>\5.12.6\msvc2017_64\lib`) to the `LD_LIBRARY_PATH` and `DYLD_LIBRARY_PATH`, respectivley.

## Get the source code

Fork [MNE-CPP's main repository](https://github.com/mne-tools/mne-cpp) to your own GitHub account. For a detailed overview of how to fork a repository, we recommend checking out the [guide on the official GitHub website](https://help.github.com/en/github/getting-started-with-github/fork-a-repo). 

Clone the fork to your local machine:

    $ git clone https://github.com/<YourGitUserName>/mne-cpp.git

Setup a new remote pointing to MNE-CPP's main repository:

    $ git remote add upstream https://github.com/mne-tools/mne-cpp.git

Every time you want to update to the newest changes use:

    $ git rebase upstream/master

## Compile the source code

| **Please note:** If you are working on an operating system on a "non-western" system, i.e. Japan, you might encounter problems with unicode interpretation. Please do the  following: Go to Control Panel -> Language and Region -> Management tab -> Language Settings for non-Unicode Programs -> Set to English (U.S.) -> Reboot your system. |

1. Go to your cloned repository folder and run the `mne-cpp.pro` file with QtCreator.
2. The first time you open the mne-cpp.pro file you will be prompted to configure the project with a pre-defined kit. Select the appropriate kit, e.g., `Desktop Qt 5.12.6 MSVC2017 64bit` and configure the project.
3. In QtCreator select the Release mode in the lower left corner.
4. In the Qt Creator's Projects window, right mouse click on the top level mne-cpp tree item and select Run qmake. Wait until progress bar in lower right corner turns green (this step may take some time).
5. Right mouse click again and then hit Build (this step may take some time). Wait until progress bar in lower right corner turns green.
6. After the build process is finished, go to the `mne-cpp/bin` folder. All applications and libraries should have been created throughout the build process.

## Test the build

In order to run the examples you must download the MNE-Sample-Data-Set from [here](https://osf.io/86qa2/download) and extract the files to `mne-cpp/bin/MNE-sample-data`. Once finished you can try to run one of the examples, e.g., ex_disp3D. If the build was successfull the example should start and display a window including a 3D brain as well as a source localization result.