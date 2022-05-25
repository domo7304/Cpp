from unittest import result
import matplotlib.pyplot as plt
import numpy as np

class LogisticRegression:

    # class initialization
    def __init__(self, learning_rate = 0.01, epoch = 2000):
        self.learning_rate = learning_rate
        self.epoch = epoch # 얼마정도가 적절한 epoch 인지는 알 수 없음. 실제 학습 후 조정해나가야 함.
        self.w = [] # weight 초기화
        self.b = 0 # bias 초기화
    
    # weight, bias initialization
    def initialize_weight(self, dim):
        w = np.random.normal(0, 1, (dim, 1))
        b = np.random.rand(1)
        return w, b

    # sigmoid funtion
    def sigmoid(self, x):
        return 1 / (1 + np.exp(-x))

    def hypothesis(self, w, X, b):
        y_hat = self.sigmoid(np.matmul(X,w) + b) # y_hat = sigmoid(Xw + b) 를 구현한 것
        y_hat = np.squeeze(y_hat) # squeeze : 크기가 1인 무의미한 차원을 없애준다. ex) [[1, 2, 3]] -> [1, 2, 3]
        return y_hat
    
    # implements cost function (Binary Cross Entropy)
    def cost(self, y_hat, y, N):
        # BCE : class entropy 를 binary classification 문제에 활용하기 위해 정의된 손실함수
        cost = -(1/N) * np.sum(y*np.log(y_hat) + (1-y) * np.log(1-y_hat))
        cost = np.squeeze(cost)
        return cost

    # implements gradient function
    def cal_gradient(self, w, y_hat, X, y):
        N = X.shape[1]
        delta_w = (1/N) * np.matmul(X.T, (y_hat-y))
        delta_b = (1/N) * np.sum(y_hat-y)
        grads = {"delta_w" : delta_w, "delta_b" : delta_b}
        return grads

    # grads, cost 한 번에 계산
    def gradient_position(self, w, b, X, y):
        N = X.shape[0]
        y_hat = self.hypothesis(w, X, b)
        cost = self.cost(y_hat, y, N)
        grads = self.cal_gradient(w, y_hat, X, y)
        return grads, cost

    def gradient_descent(self, w, b, X, y, print_cost = False):
        costs = []

        for i in range(self.epoch):
            grads, cost = self.gradient_position(w, b, X, y)

            # gradient_position(w, b, X, y) 를 통해 계산한 grads dictionary 에서 값 가져오기
            delta_w = grads["delta_w"]
            delta_b = grads["delta_b"]

            delta_w = delta_w.reshape(-1, 1)

            # weight, bias 업데이트
            w = w - (self.learning_rate * delta_w)
            b = b - (self.learning_rate * delta_b)
            if i % 100 == 0:
                costs.append(cost)

            if print_cost and i % 100 == 0:
                print("Cost after iteration % i : % f" %(i, cost))
            
            params = {"w" : w, "b" : b}
            grads = {"delta_w" : delta_w, "delta_b" : delta_b}

        return params, costs

    def predict(self, X):
        X = np.array(X)
        N = X.shape[0]

        Y_prediction = np.zeros(N)

        w = self.w.reshape(X.shape[1], 1)
        b = self.b

        y_hat = self.hypothesis(w, X, b)

        for i in range(len(y_hat)):
            if y_hat[i] >= 0.5:
                Y_prediction[i] = 1
            else:
                Y_prediction[i] = 0
        return Y_prediction

    def train_model(self, X_train, Y_train, X_test, Y_test, print_cost = False):
        dim = np.shape(X_train)[1]
        w, b = self.initialize_weight(dim)
        parameters, costs = self.gradient_descent(w, b, X_train, Y_train, print_cost = False)

        self.w = parameters["w"]
        self.b = parameters["b"]

        Y_prediction_test = self.predict(X_test)
        Y_prediction_train = self.predict(X_train)

        train_score = 100 - np.mean(np.abs(Y_prediction_train - Y_train)) * 100
        test_score = 100 - np.mean(np.abs(Y_prediction_test - Y_test)) * 100
        print("test accuracy : {} %" .format(100 - np.mean(np.abs(Y_prediction_test - Y_test)) * 100))

        result_dict = {#"costs": costs,
                    #"Y_prediction_test": Y_prediction_test,
                    #"Y_prediction_train": Y_prediction_train,
                    "w": self.w,
                    "b": self.b,
                    "learning_rate": self.learning_rate,
                    "num_iterations": self.epoch,
                    "train accuracy": train_score,
                    "test accuracy": test_score}
        return result_dict

# Load data set
xy_data = np.load("./data2.npz")
# dictionary 형태에서 key 로 각각 가져오는 것
X = xy_data['x']
Y = xy_data['y']

# 데이터셋의 90% 는 train set 으로 사용
train_number = int(Y.shape[0] * 0.9)

X_train = X[:train_number, :]
Y_train = Y[:train_number]

X_test = X[train_number:, :]
Y_test = Y[train_number:]

LC_cls = LogisticRegression()
result_dict = LC_cls.train_model(X_train, Y_train, X_test, Y_test)
print(result_dict)