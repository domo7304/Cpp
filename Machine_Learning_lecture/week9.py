import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import time

data = pd.read_csv(https://raw.githubusercontent.com/Baakchsu/LinearRegression/master/weight-height.csv)

class LinearRegression:
    def fit(self, X, Y):
        X = np.array(X).reshape(1, -1);
        Y = np.array(Y).reshape(1, -1);
        x_shape = X.shape
        num_var = x_shape[0]
        self.parameter_cache = []
        self.weight = np.random.normal(0, 1, (num_var, 1))
        self.bias = np.random.rand(1)
        self.num_iteration = 50

        for t in range(self.num_iteration):
            N = x_shape[1]
            self.delta_W = 2/N * (np.sum(np.multiply(((np.matmul(self.weight, X) + self.bias) - Y), X)))
            self.delta_bias = 2/N * (np.sum(((np.matmul(self.weight, X) + self.bias) - Y)))
            self.weight -= 0.1 * self.delta_W
            self.bias -= 0.1 * self.delta_bias
            self.parameter_cache.append(np.array(self.weight, self.bias))
        return self.weight, self.bias, self.parameter_cache

    def predict(self, X):
        print(X.shape)
        product = np.matmul(self.weight, np.array(X).reshape(1, -1)) + self.bias
        return product.reshape(-1)

    
reg = LinearRegression()

x = (data['Weight'] - data['Weight'].mean()) / data['Weight'].std()
y = (data['Height'] - data['Height'].mean()) / data['Height'].std()

params = reg.fit(x[:-180], y[:-180])
pred = reg.predict(np.array(x[:-180]))

plt.scatter(x[-180:], y[-180:])
plt.plot(x[-180:], pred, 'red')
plt.savefig('plot_fit.png')