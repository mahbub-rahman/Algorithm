#include <iostream>

using namespace std;
int c[100],s[100];

int Coin(int d[],int NumOfcoin,int amount)
{
	
	c[0] = s[0] =0;
	int coin,min;
	for(int i=1;i<=amount;i++){
		min = 1<<28;
		for(int j = 1;j<=NumOfcoin;j++){
			if(d[j-1] <= i){
				if( 1+c[i-d[j-1]] < min){
					min = 1+c[i-d[j-1]];
					coin = j;
				}
			}
		}
		c[i] = min;
		s[i] = coin;
	}
	return c[amount];
}
void print_solution(int d[],int A)
{
	while(A>0){
		cout<<d[(s[A])-1]<<" ";
		A = A-d[(s[A])-1];
	}
	return ;
}
int main() {
	int d[] = {1,2,5};
	int n = 3;
	int t = 7;
	
	cout<<Coin(d, n, t)<<endl;
	print_solution(d, t);
}