import numpy as np
import pandas as pd
from sklearn import datasets
#
from sklearn import model_selection
from sklearn.linear_model import LogisticRegression
from sklearn import metrics

dataset = datasets.load_digits()
x_data = dataset.data
y_data = dataset.target

#print(x_data)
#print(y_data) 

####################

x_train, x_test, y_train, y_test = model_selection.train_test_split(x_data, y_data, test_size=0.33)

estimator = LogisticRegression(max_iter=100, tol=0.0001, penalty='l2', C=1.0)

estimator.fit(x_train, y_train)

y_predict = estimator.predict(x_train) 
score = metrics.accuracy_score(y_train, y_predict)
print(score) #0.9958437240232751

y_predict = estimator.predict(x_test) 
score = metrics.accuracy_score(y_test, y_predict)
print(score) #0.9562289562289562