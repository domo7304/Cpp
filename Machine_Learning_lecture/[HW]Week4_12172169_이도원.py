#%%
import numpy as np
import matplotlib.pyplot as plt

K = 10
rand_data = np.random.rand(2, 100)
x = np.random.rand(2, 1)

dataLen = rand_data.shape[1]

if K < dataLen:
    K = K
else:
    K = dataLen

# 유클리디언 거리 이용
distance = np.sqrt(((rand_data - x) ** 2).sum(axis=0))
idx = np.argsort(distance)
neighborIndex = idx[:K]

#시각화 코드 작성
plt.plot(rand_data[0, :], rand_data[1, :], "ok", label="Data")
plt.plot(x[0, 0], x[1, 0], 'or', label='Query')
plt.plot(rand_data[0, neighborIndex], rand_data[1, neighborIndex], 'o',
        markerfacecolor='None', markersize=12,
        markeredgewidth = 0.5, label='KNN')
plt.legend(loc='upper right')
plt.title('KNN search')
plt.show()

# 맨해튼 거리 이용
x = np.random.rand(2, 1)
distance = np.abs(rand_data - x).sum(axis=0)
idx = np.argsort(distance)
neighborIndex = idx[:K]

#시각화 코드 작성
plt.plot(rand_data[0, :], rand_data[1, :], "ok", label="Data")
plt.plot(x[0, 0], x[1, 0], 'or', label='Query')
plt.plot(rand_data[0, neighborIndex], rand_data[1, neighborIndex], 'o',
        markerfacecolor='None', markersize=12,
        markeredgewidth = 0.5, label='KNN')
plt.legend(loc='upper right')
plt.title('KNN search')
plt.show()

# 코사인 거리 이용
rand_data_tmp = np.transpose(rand_data)
for i in range(len(rand_data_tmp)):
    distance[i] = 1 - np.dot(rand_data_tmp[i], x)/ (np.linalg.norm(rand_data_tmp[i]) * np.linalg.norm(x))
idx = np.argsort(distance)
neighborIndex = idx[:K]

# 시각화 코드 작성
plt.plot(rand_data[0, :], rand_data[1, :], "ok", label="Data")
plt.plot(x[0, 0], x[1, 0], 'or', label='Query')
plt.plot(rand_data[0, neighborIndex], rand_data[1, neighborIndex], 'o',
        markerfacecolor='None', markersize=12,
        markeredgewidth = 0.5, label='KNN')
plt.legend(loc='upper right')
plt.title('KNN search')
plt.show()
# %%
