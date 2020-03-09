# Testing 1
# temp  =  neuronalNetwork( [2, 2, 1], 'lineal' )
# print( temp.forward([   [0, 1, 0, 1],
#                         [0, 0, 1, 1]]) )

import math

def sigmoid( x ):
    return 1/(1+math.exp(-x))

x = 1
y = 1

a = sigmoid(2.26691517*x+2.3062711*y+-0.94086962)
b = sigmoid(2.20302076*x+1.89332784*y+-0.34820717)
c = sigmoid(0.95590418*a+0.27957298*b+-0.77824137)
print(c)