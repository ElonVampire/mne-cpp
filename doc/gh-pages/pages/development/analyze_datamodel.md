---
title: Creating a new data model
parent: MNE Analyze
grand_parent: Develop
nav_order: 1
---

# Creating a new data model

## Overview

All of the data models used in MNE Analyze are subclassed from the same base, AbstactModel (applications/mne_analyze/libs/anShared/Model/abstactmodel.h).

## Subclassing AbstactModel

Abstract model is itself a subclass of an abstract class, QAbstactItemModel. To correctly sub-class it, all of the pure virtual functions from QAbstractItemModel and AbstactModel must be implemented. For more information on the QAbstactItemModel functions, see the [Qt documentation](https://doc.qt.io/qt-5/qabstractitemmodel.html).

The following are the functions that need to be implemented:

### getType()

Returns the type of the model. These types are declared in applications/mne_analyze/libs/anShared/Utils/types.h, and when creating a new model, a new item needs to be added to enum `MODEL_TYPE`.

### data()

Returns data stored in model based on the input model index and role.

### flags()

Returns the flags for the model index passed to the function.

### index()

Return an index for the data based on the input row and column.

### parent()

Return a model index to the parent of this model. IF there is no parent, return an empty QModelIndex

### rowCount()

Return an appropriate value depending on how you are organizing or representing your data. The FiffRawViewModel, for example, returns the amount of channels for which it has data.

### columnCount()

Return an appropriate value depending on how you are organizing or representing your data. The Annotation Model, for example, returns the number of columns of data it has to display.

## Loading/Adding to Data Loader and Data Manager

If your data model will be loading data from a file, make sure that file type is included in DataLoader::loadFilePath() so the user can load in that file type. To save to a file, implement the function saveToFile() from the AbstractModel, and ensure that your file type is included in DataLoader::onSaveFilePressed().

To add your model to the data manager, add it to either addModel or loadModel in AnalyzeData.h, depending on whether you will be loading data from inside the application or from a file. You need to define the type of data your model corresponds to, bidsviewmodel.h for possible types, or add a new one.
