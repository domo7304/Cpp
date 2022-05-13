import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv('./ML_week9_data.csv')

class LinearRegression: 
    def fit(self, X, Y):
        X = np.array(X).reshape(1, -1);
        Y = np.array(Y).reshape(1, -1);
        
        self.weight = np.array(np.cov(X, Y)[0][1] / np.var(X)).reshape(1, 1)
        self.bias = np.mean(Y) - self.weight*np.mean(X)

        return self.weight, self.bias

    def predict(self, X):
        product = np.matmul(self.weight, np.array(X).reshape(1, -1)) + self.bias
        return product.reshape(-1)

    
reg = LinearRegression()

x = (data['Weight'] - data['Weight'].mean()) / data['Weight'].std()
y = (data['Height'] - data['Height'].mean()) / data['Height'].std()

'''
x = (data['Weight'] - data['Weight'].min()) / (data['Weight'].max() - data['Weight'].min())
y = (data['Height'] - data['Height'].min()) / (data['Height'].max() - data['Height'].min())
'''

params = reg.fit(x[:-180], y[:-180])
pred = reg.predict(np.array(x[-180:]))

plt.scatter(x[-180:], y[-180:])
plt.plot(x[-180:], pred, 'red')
plt.text(0.25, -2.6, 'MLE, Z-score')
#plt.savefig('MLE, Z-score.png')
#plt.text(0.5, 0.08, 'MLE, min-max')
#plt.savefig('MLE, min-max')