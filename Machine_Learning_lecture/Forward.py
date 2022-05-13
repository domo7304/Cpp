import numpy as np

target = np.array([[0.6], [0.8], [0.5]])
input = np.array([[0.9], [0.1], [0.8]])
w1 = np.array([[0.9, 0.3, 0.4], [0.2, 0.8, 0.2], [0.1, 0.5, 0.6]])
w2 = np.array([[0.3, 0.7, 0.5], [0.6, 0.5, 0.2], [0.8, 0.1, 0.9]])
learningRate = 0.01

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def backprop_postproc(self, loss, aux):
        # aux == Y - Predict
        shape = aux.shape

        loss_square = np.ones(shape) / np.prod(shape)
        square_diff = 2 * aux
        diff_output = 1
       
        output = diff_output * square_diff * loss_square * loss

        return output

def backprop_neuralnet(self,output, x):
        output_w = x.transpose()

        w = np.matmul(output_w, output)

        self.weight -= self.LEARNING_RATE * w

def forward(x, w1, w2):
    x_hidden = w1.dot(x)
    o_hidden = sigmoid(x_hidden)
    x_output = w2.dot(o_hidden)
    o_output = sigmoid(x_output)

'''
target = np.array([[0.6], [0.8], [0.5]])
x = np.array( [[0.9], [0.1], [0.8]] )
w_input_hidden = np.array([[0.9, 0.3, 0.4], [0.2, 0.8, 0.2], [0.1, 0.5, 0.6]])
x_hidden = w_input_hidden.dot(x)

o_hidden = sigmoid(x_hidden)

w_hidden_output = np.array([[0.3, 0.7, 0.5], [0.6, 0.5, 0.2], [0.8, 0.1, 0.9]])
x_output = w_hidden_output.dot(o_hidden)

o_output = sigmoid(x_output)
#o_output = np.floor(o_output * 1000) / 1000
'''