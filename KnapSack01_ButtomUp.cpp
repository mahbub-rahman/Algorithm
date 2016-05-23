#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int dp[100][100];

void print_solution(int wt[],int i,int w)
{
	while(i && w){
		if(dp[i][w] != dp[i-1][w]){
			
			cout<<i<<" ";
			i = i-1, w = w-wt[i];
		}else{
			i = i-1;
		}
	}
	return;
}

int Knapsak(int price[],int wt[],int item,int Capacity)
{
	
	for(int i=0;i<=item;i++){
		for(int j=0;j<=Capacity;j++){
			if(i==0 || j==0){
				dp[i][j] = 0;
			}
			else if(wt[i-1] <= j){
				dp[i][j] = max(price[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	return dp[item][Capacity];
}


int main() {
	int val[] = {100, 20, 60,40};
	int wt[]={3, 2, 4,1};
	int  W = 5;
	int n = sizeof(val)/sizeof(val[0]);
	
	printf("\n%d\n", Knapsak(val,wt,n,W));
	print_solution(wt,n, W);
	
	return 0;
}