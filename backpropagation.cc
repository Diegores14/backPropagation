#include <bits/stdc++.h>
using namespace std;
typedef vector< vector<double> > matrix;
matrix mtr( int n, int m, double value = 0 ) { return matrix(n, vector<double>( m, value ) ); }

matrix operator *( matrix a, matrix b ) {
    assert( a[0].size() == b.size() );
    int n = a.size(), m = b[0].size();
    matrix answer = mtr(n,m);
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < m; j++ ) {
            for( int k = 0; k < b.size(); k++ ) {
                answer[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    return answer;
}

matrix operator +( matrix a, matrix b ) {
    assert( a.size() == b.size() && a[0].size() == b[0].size() );
    int n = a.size(), m = a[0].size();
    matrix answer = mtr(n,m);
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < m; j++ ) {
            answer[i][j] = a[i][j]+b[i][j];
        }
    }
    return answer;
}

matrix operator +( double a, matrix b ) {
    int n =b.size(), m = b[0].size();
    matrix answer = mtr(n,m);
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < m; j++ ) {
            answer[i][j] = a+b[i][j];
        }
    }
    return answer;
}

matrix operator /( double a, matrix b ) {
    int n =b.size(), m = b[0].size();
    matrix answer = mtr(n,m);
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < m; j++ ) {
            answer[i][j] = a/b[i][j];
        }
    }
    return answer;
}

matrix operator *( double a, matrix b ) {
    int n = b.size(), m = b[0].size();
    matrix answer = mtr(n,m);
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < m; j++ ) {
            answer[i][j] = a*b[i][j];
        }
    }
    return answer;
}

matrix transponse( matrix a ) {
    matrix answer = mtr(a[0].size(), a.size());
    for( int i = 0; i < a.size(); i++ ) {
        for( int j = 0; j < a[0].size(); j++ ) {
            answer[j][i] = a[i][j];
        }
    }
    return answer;
}

matrix expMatrix( matrix a ) {
    matrix answer = a;
    for( int i = 0; i < a.size(); i++ ) {
        for( int j = 0; j < a[i].size(); j++ ) {
            answer[i][j] = exp( a[i][j] );
        }
    }
    return answer;
}

matrix squareMatrix( matrix a ) {
    matrix answer = a;
    for( int i = 0; i < a.size(); i++ ) {
        for( int j = 0; j < a[i].size(); j++ ) {
            answer[i][j] = a[i][j]*a[i][j];
        }
    }
    return answer;
}

matrix maximumMatrix( matrix a, matrix b ) {
    assert( a.size() == b.size() && a[0].size() == b[0].size() );
    matrix answer = mtr( a.size(), a[0].size() );
    for( int i = 0; i < a.size(); i++ ) {
        for( int j = 0; j < a[i].size(); j++ ) {
            answer[i][j] = max( a[i][j], b[i][j] );
        }
    }
    return answer;
}

matrix multRectMatrix( matrix a, matrix b ) {
    assert( a.size() == b.size() && a[0].size() == b[0].size() );
    matrix answer = mtr( a.size(), a[0].size() );
    for( int i = 0; i < a.size(); i++ ) {
        for( int j = 0; j < a[0].size(); j++ ) {
            answer[i][j] = a[i][j]*b[i][j];
        }
    }
    return answer;
}

matrix autoCompletedMatrix( matrix a, int n ) {
    a = transponse( a );
    matrix answer = mtr( n, a[0].size() );
    for( int i = 0; i < n; i++ ) {
        answer[i] = a[0];
    }
    return transponse( answer );
}

void print( matrix a ) {
    cout << "PRINT\n";
    for( int i = 0; i < a.size(); i++ ) {
        for( int j = 0; j < a[i].size(); j++ ) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

class neuronalNetwork {
    public:
    vector< matrix > W, B, A, Z, dZ;
    neuronalNetwork( vector< int > &layers, int activation ) {
        W.emplace_back( matrix() );
        B.emplace_back( matrix() );
        Z.emplace_back( matrix() );
        dZ.emplace_back( matrix() );
        A.emplace_back( matrix() );
        for( int i = 1; i < layers.size(); i++ ) {
            W.emplace_back( mtr(layers[i], layers[i-1]) );
            B.emplace_back( mtr(layers[i], 1) );
            Z.emplace_back( mtr() );
            dZ.emplace_back( mtr() );
            A.emplace_back( matrix() );
        }
    }
    void Forward( matrix a ) {
        A[0] = a;
        for( int l = 1; l < W.size(); l++ ) {
            Z = W[l]*A[l-1] + autoCompletedMatrix( b, a[0].size() );
            A = 
        }
    }

    void train( matrix a, matrix T ) {
        
    }
    // double tansig(x, derivative=False):
    //   double arg = (np.exp(x) - np.exp(-x))/(np.exp(x) + np.exp(-x))            // Sacar la exponecial 
    //   return 1-np.square(arg) if derivative else  arg#2/(1+np.exp(-2*x))-1
    matrix lineal( matrix x, bool derivative = false ) {
        return derivative? mtr(x.size(), x[0].size(), 1) : x;
    }
    matrix relu( matrix x, bool derivative=false ) {
        if( derivative ) {
            matrix answer = mtr(x.size(), x[0].size());
            for( int j = 0; j < s.size(); j++ )
                for( int i = 0; i < x[j].size(); i++ ) 
                    answer[j][i] = double(x[0][i] > 0);
            return answer;
        }
        return maximumMatrix( mtr(x.size(), x[0].size()), x ); 
    }
    matrix sigmoid( matrix x, bool derivative=false ) {
        matrix arg = 1/(1 + expMatrix( -1*x ) );
        return derivative? multRectMatrix( arg , 1 + (-1.0*arg) ) : arg;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(3);
    matrix a = mtr(1,3), b = mtr(2, 3);
    for( int i = 0; i < 1; i++ ) {
        for( int j = 0; j < 3; j++ ) {
            a[i][j] = i+j;
        }
    }
    neuronalNetwork temp;
    cout << exp(-1) << '\n';
    print( a );
    print( temp.lineal(a, false) );
    return 0;
}