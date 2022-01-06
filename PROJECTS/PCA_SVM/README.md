# ML implementation in Arduino environment
## PCA and SVM algorithms are exported from python to compile in Arduino

### Dataset:

 This dataset presents an intelligent electronic system to detect a person's posture when sitting in a wheelchair. The primary use of the proposed system is to warn an improper posture to prevent major health issues. Available in:
[Wheelchair human position](https://ieee-dataport.org/open-access/data-set-wheelchair-sensors).
Main python library and more information in: [Eloquentarduino] (https://eloquentarduino.github.io/)

### First steps:
Please, read and follow the python code in this repositorie.

### Python code: 
```
#Libraries
from micromlgen import port
```
# ML Arduino code

Follow this repositorie:
[Supervised ML algorithms](https://github.com/puldavid87/ITU-DK/tree/main/SUPERVISED%20MACHINE%20LEARNING)

Before to deploy ML algorithms, normalize the income data
* y = (x – min) / (max – min)

PCA.h and SVM are export models

### Python code: 
```
import pandas as pd
import numpy as np
from sklearn.svm import SVC
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix
from micromlgen import port
from sklearn.preprocessing import MinMaxScaler


dataset=pd.read_csv('dataset.csv', sep=',')
sc=MinMaxScaler()

X= dataset.iloc[:307,:-1].values
y=dataset.iloc[:307,-1].values
X=sc.fit_transform(X)
X_train, X_test,y_train,y_test=train_test_split(X,y,test_size=0.2, random_state=0)

classifier=SVC(kernel='poly', random_state=0)
classifier.fit(X_train,y_train)


y_pred=classifier.predict(X_test)
print(confusion_matrix(y_test,y_pred))
###export
export=SVC(kernel='poly', gamma=0.001).fit(X, y)

with open('svm.h', 'w') as file:
    file.write(port(export))
```
