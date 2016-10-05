import numpy as np

class Neural_Network(object):
    def __init__(self):
        # Define Hyperparameters
        self.inputLayerSize = 2
        self.outputLayerSize = 1
        self.hiddenLayerSize = 3

        # Weights (Parameters)
        self.weights = {}
        # random number follows normal distribution
        self.weights[0] = np.random.randn(self.inputLayerSize, self.hiddenLayerSize)
        self.weights[1] = np.random.randn(self.hiddenLayerSize, self.outputLayerSize)

        self.activity = {}
        self.activation = {}

    def forward(self, X):
        # Propagate through the network
        prevLayer = X
        for i in range(2):
            # Activate(X*Weights)
            self.activity[i+1] = np.dot(prevLayer, self.weights[i])
            self.activation[i+1] = self.sigmoid(self.activity[i+1])
            prevLayer = self.activation[i+1]
        return prevLayer

    def sigmoid(self, z):
        # Apply the sigmoid activation function
        return 1/(1+np.exp(-z))

    def dSigmoid(self, z):
        # Derivative of Sigmoid function
        return (np.exp(-z))/((1+np.exp(-z))**2)

    def dCostdW(self, x, y):
        # Derivative of Cost Function = sigma (1/2)(y-yhat)^2 with respect to W

        dJdW = {};

        self.yhat = self.forward(x)

        delta3 = np.multiply(-(y - self.yHat), self.dSigmoid(self.activity[2]))
        dJdW[1] = np.dot(self.activation[1].T, delta3)

        delta2 = np.dot(delta3, self.weights[1].T)*self.dSigmoid(self.activity[1])
        dJdW[0] = np.dot(x.T, delta2)

        return dJdW

        #https://www.youtube.com/watch?v=pHMzNW8Agq4&index=5&list=PLiaHhY2iBX9hdHaRr6b7XevZtgZRa1PoU arghh fk it

def main():
    ix = np.array([[3,5],[5,1],[10,2]], dtype=float)
    iy = np.array([[75], [82], [93]], dtype=float)

    # scaling
    ix = ix/np.amax(ix, axis=0)
    iy = iy/100

    network = Neural_Network()
    print(network.forward(ix))

main()
