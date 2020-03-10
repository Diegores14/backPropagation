import numpy as np


class neuronalNetwork:
    def __init__( self, layers, activation ):
        self.f = { 'lineal': self.lineal, 'relu': self.relu, 'sigmoid': self.sigmoid }
        self.layers = layers
        self.alpha = 0.1
        self.activation = activation
        self.L = len( self.layers ) - 1 
        self.W = [ np.array([]) ]
        self.B = [ np.array([]) ]
        self.A = [ np.array([]) ]
        self.Z = [ np.array([]) ]
        self.dZ = [ np.array([]) ]
        self.m = 1
        i = 1
        while( i <= self.L ):
            self.W.append( np.random.rand( layers[i], layers[i-1] ) )
            self.B.append( np.random.rand( layers[i], 1 ) )
            self.A.append( np.array( [] ) )
            self.Z.append( np.array( [] ) )
            self.dZ.append( np.array( [] ) )
            i += 1

    # def tansig(self, x, derivative=False):
    #   arg=(np.exp(x) - np.exp(-x))/(np.exp(x) + np.exp(-x))
    #   return 1-np.square(arg) if derivative else  arg#2/(1+np.exp(-2*x))-1

    def lineal( self, x, derivative=False ):
        return np.ones( x.shape ) if derivative else  x

    def relu( self, x, derivative=False ):
        return np.where(x>0, 1, 0) if derivative else np.maximum(np.zeros(x.shape),x)

    def sigmoid( self, x, derivative=False ):
        arg=1/(1+np.exp(-x))
        return np.multiply(arg, 1-arg) if derivative else arg

    def softmax( self, x, derivate=False ):
        arg = np.exp( x )
        return arg if derivate else arg/np.sum( arg, axis=0 )

    def train( self, A, T, iter ):
        self.m = A.shape[1]
        for i in range( iter ):
            self.forward( A )
            self.Backward( T )
            self.Error( T )

    def forward( self, A ):
        l = 1
        self.A[0] = A
        while l <= self.L:
            self.Z[l] = np.dot( self.W[l], self.A[l-1] ) + self.B[l]
            self.A[l] = self.f[self.activation]( self.Z[l] )
            l += 1
        return self.A[self.L]

    def Backward( self, T ):
        l = self.L
        self.dZ[l] = (-1.0/self.m)*np.multiply( (T - self.A[l]), self.f[self.activation]( self.Z[l], True ) )
        dw = np.dot( self.dZ[l], np.transpose( self.A[l-1] ) )
        self.W[l] = self.W[l] - self.alpha*dw
        self.B = self.B - self.alpha*np.sum( self.dZ[l], axis = 1 )
        l -= 1
        while( 0 < l ):
            self.dZ[l] = np.multiply( np.dot( np.transpose( self.W[l+1] ), self.dZ[l+1] ), self.f[self.activation]( self.Z[l], True ) )
            dw = np.dot( self.dZ[l], np.transpose( self.A[l-1] ) )
            self.W[l] = self.W[l] - self.alpha*dw
            db = np.sum( self.dZ[l], axis = 1 )
            db = db.reshape( (db.shape[0], 1) )
            self.B[l] = self.B[l] - self.alpha*db
            l -= 1

    def Error( self, T ):
        print( (1.0/self.m)*(1/2.0)*sum( sum( np.square(T - self.A[self.L]) ) ) )


# Testing
# RN = neuronalNetwork( [2,2,1], 'relu' )
# A = np.array( [[0, 1, 0, 1],
#             [0, 0, 1, 1]])
# T = np.array( [[0, 1, 1, 0]] )
# RN.train(A, T, 50000)
# print( RN.forward(A) )
# print( RN.W )
# print( RN.B )
