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
print(pca.components_)

#SVM MODEL
from sklearn.svm import SVC
classifier=SVC(kernel= 'poly', random_state=0)
classifier.fit(X_train,y_train)
y_pred=classifier.predict (X_test)
cm=confusion_matrix(y_test,y_pred) 
print(cm)
##########################################################################################################
#export models
from micromlgen import port
#You can copy from the console
print(port(pca))
# Also, you can export the model in txt file.
c_code=SVC(kernel='poly', gamma=0.001).fit(X_train, y_train)
f = open("output.txt", "a")
print(port(c_code), file=f)  
f.close()
