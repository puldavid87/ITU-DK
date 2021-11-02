# ML implementation in Arduino environment
## PCA low-dimensional training set stored into the Arduino and k-NN algorithm as classifier

### Dataset:

 This dataset presents an intelligent electronic system to detect a person's posture when sitting in a wheelchair. The primary use of the proposed system is to warn an improper posture to prevent major health issues. Available in:
[Wheelchair human position](https://ieee-dataport.org/open-access/data-set-wheelchair-sensors).

### Python code: 
```
#Libraries
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.decomposition import PCA

#import dataset
dataset=pd.read_csv('database.csv', sep=';')
X= dataset.iloc[:307,:-1].values
y=dataset.iloc[:307,-1].values

#normalize the database
from sklearn.preprocessing import MinMaxScaler
sc=MinMaxScaler()
X=sc.fit_transform(X)

#PCA implementetions
pca=PCA(n_components=2)
X=pca.fit_transform(X)

#split the dataset
X_train, X_test,y_train,y_test=train_test_split(X,y,test_size=0.2, random_state=0)
#Convert to dataframe
trainingset =pd.DataFrame(X_train)
#round to 2 decimals
trainingset=round(trainingset,2)
#concat X_train with y_train
trainingset=pd.concat([trainingset,pd.DataFrame(y_train)], axis=1)
#export to csv file
trainingset.to_csv('trainingset.csv', sep=';')
```
#ML Arduino code
```
Follow this repositorie:
[Supervised ML algorithms](https://github.com/puldavid87/ITU-DK/tree/main/SUPERVISED%20MACHINE%20LEARNING)
```
#functions.cpp:
Low-dimensional training set is allocated in FLash memory (const PROGMEM)
Before to deploy k-NN, normalize the income data
* y = (x – min) / (max – min)

Classification algorith is followed.
