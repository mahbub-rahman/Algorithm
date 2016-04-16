#include <iostream>
#include <string>
using namespace std;
#define MAX 100
int row[MAX];
int col[MAX];
int dp[MAX][MAX];
int Matrix_mult(int beg,int end)
{
	if(beg >= end) return 0;
	
	if(dp[beg][end] >= 0 ) return dp[beg][end];
	int res = 1<<28;
	for(int mid = beg; mid<end;mid++){
		
		int left = Matrix_mult(beg, mid);
		int right = Matrix_mult(mid+1, end);
		int leftright = row[beg]*col[mid]*col[end];
		int total = left + right + leftright;
		res = min(res,total);
	}
	dp[beg][end] = res;
	return dp[beg][end];
	
} 

int main(int argc, char *argv[]) {
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>row[i]>>col[i];
	}
	memset(dp, -1, sizeof(dp));
	cout<<Matrix_mult(0,n-1)<<endl;
}