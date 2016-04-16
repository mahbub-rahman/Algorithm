#include <iostream>

using namespace std;

int CutRod(int price[],int len)
{
	if(len <= 0)
		return 0;
	int maxValue = 0;
	for(int i=0;i<len;i++){
		
		maxValue = max(maxValue,price[i]+CutRod(price,len-i-1));
	}
	return maxValue;
}
int MemoRodCutDP(int price[],int n,int r[])
{
	if(r[n] >= 0) return r[n];
	int q;
	if(n==0) q = 0;
	else{
		q = -1<<28;
		for(int i=1;i<n;i++){
			q = max(q,price[i]+MemoRodCutDP(price,n-i-1,r));
		}
	}
	r[n] = q;
	return q;
}
int MemoRodCut(int price[],int n)
{
	int r[n+2];
	for(int i=0;i<n;i++) r[i] = -1<<28;
	return MemoRodCutDP(price,n,r);
}

int main(int argc, char *argv[]) {
	int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
	cout<<MemoRodCut(price, 8)<<endl;
}