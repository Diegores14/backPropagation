import numpy as np


class neuronalNetwork:
    def __init__( self, layers ):
        self.W = [ np.array([]) ]
        self.B = [ np.array([]) ]
        self.A = [ np.array([]) ]
        self.Z = [ np.array([]) ]
        self.dZ = [ np.array([]) ]
        self.f = { 'lineal': self.lineal, 'relu': self.relu, 'sigmoid': self.sigmoid }
        self.layers = layers

    # def tansig(self, x, derivative=False):
    #   arg=(np.exp(x) - np.exp(-x))/(np.exp(x) + np.exp(-x))
    #   return 1-np.square(arg) if derivative else  arg#2/(1+np.exp(-2*x))-1

    def lineal( self, x, derivative=False ):
        return np.ones( x.shape ) if derivative else  x

    def relu( self, x, derivative=False ):
        return (0+(
            >0)) if derivative else np.maximum(np.zeros(x.shape),x)

    def sigmoid( self, x, derivative=False ):
        arg=1/(1+np.exp(-x))
        return np.multiply(arg, 1- arg) if derivative else arg

    def train( self, A, T ):
        self.W = [ np.array([]) ]
        self.B = [ np.array([]) ]
        self.A = [ np.array([]) ]
        self.Z = [ np.array([]) ]
        self.dZ = [ np.array([]) ]
        self.A[0] = A
        i = 1
        while( i < len(self.layers) ):
            self.W.append( np.random.rand( layers[i], layers[i-1] ) )
            self.B.append( np.zeros( ( layers[i], 1 ) ) )
            self.A.append( np.zeros( ( layers[i], A.shape[1] ) ) )
            self.Z.append( np.zeros( ( layers[i], A.shape[1] ) ) )
            self.dZ.append( np.zeros( ( layers[i], A.shape[1] ) ) )
        
temp  =  neuronalNetwork()