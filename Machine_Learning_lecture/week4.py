from math import dist
import numpy as np
import matplotlib.pyplot as plt

K = 10
rand_data = np.random.rand(2, 100) # 2차원의 데이터를 100개 생성한다는 의미
x = np.random.rand(2, 1) # 2차원에서의 하나의 데이터. 얘를 기준점으로 생각할 것

dataLen = rand_data.shape[1]

if K < dataLen:
    K = K
else:
    K = dataLen

distance = np.sqrt(((rand_data - x) ** 2).sum(axis=0))
# 기준점과 거리가 가까운 순으로 정렬, 
# argsort 는 그냥 정렬하는 게 x 정렬한 데이터의 '인덱스' 를 저장하도록 하는 것
idx = np.argsort(distance)
# 정렬된 idx 배열에서 기준점과 가까운 K개의 데이터 추출
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