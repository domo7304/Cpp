import sys
import numpy as np
import matplotlib.pyplot as plt

from sklearn.datasets import feth_openml

X, y = fetch_openml("mnist_784", version=1, return_X_y=True, as_frame=False)

train_X = np.array(_X[:10000])
test_X = np.array(_X[-10000:])

# one hot encoding
train_y = y[:-10000].astype(np.int)
test_y = y[-10000:].astype(np.int)

n_values = np.max(train_y) + 1
train_y = np.eye(n_values)[train_y]
trest_y = np.eye(n_values)[test_y]