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
ll mod = 10000000+7;
class M{
	public:
		int val[4][4];
		M(){memset(val, 0, sizeof(val));}
		void identity(){ For0(i, 2) val[i][i] = 1;}
		M operator *(M c){
			M ans;
			For0(i, 2) For0(j, 2) For0(k, 2){
				ans.val[i][j] = (ans.val[i][j] + val[i][k] * c.val[k][j])%mod;
			}
			return ans;
		}
	}A;

M power(M x, int p)
{
	if(p==1) return x;
	
	if(p&1) return x * power(x, p-1);
	M ans = power(x, p>>1);
	ans = ans * ans;
	return ans;
}
ll fibo(int a,int b,int n)
{
	if(n == 1) return b;
	A.val[0][0] = A.val[0][1] = A.val[1][0] = 1;
	A.val[1][1] = 0;
	
	A = power(A, n-1);
	
	ll ans = A.val[0][0]*b + A.val[0][1]*a ;
	return ans;
}
int main() 
{
	int a,b,n;
	
	cin >> a >> b >> n;
	
	cout << fibo(a, b, n) <<endl;
	
	return 0;
}