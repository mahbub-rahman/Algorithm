#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <list>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define For0(i,n) for(int i=0;i<(int)n;i++)
#define For1(i,n) for(int i=1;i<=(int)n;i++)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

ll mod = 100000000+7;

struct Matrix{
	int val[5][5];
	int row,col;
};

Matrix multiply(Matrix a, Matrix b)
{
	Matrix r;
	r.row = a.row;
	r.col = b.col;
	
	for(int i=0; i< r.row ; i++){
		for( int j = 0; j < r.col ; j++){
			int sum = 0;
			for(int k = 0; k < a. col ; k++){
				sum += a.val[i][k] * b.val[k][j];
				sum %= mod;
			}
			r.val[i][j] = sum;
		}
	}
	return r;
}

Matrix power(Matrix m,ll p)
{
	if(p == 1) return m;
	
	if( p&1 )
		return multiply(m,power(m, p-1));
	Matrix ret = power(m, p/2);
	ret = multiply(ret, ret);
	return ret;
}
ll fibonacci(int a,int b,int n)
{
	if(n == 1){
		return a;
	}
	
	Matrix mat; // Base Matrix 
	mat.row = 2;
	mat.col = 2;
	
	mat.val[0][0] = mat.val[0][1] = mat.val[1][0] = 1; // Base Value
	mat.val[1][1] = 0;
	mat = power(mat, n-1);
	ll ans = b * mat.val[0][0] + a * mat.val[0][1];
	ans %= mod;
	return ans ;
	
}

int main() 
{
	
	
	int a,b,n;
	a = b = 1; // strting value
	
	cin >> n; 
	
	
	cout << fibonacci(a, b, n) << endl;
	
	return 0;
}
