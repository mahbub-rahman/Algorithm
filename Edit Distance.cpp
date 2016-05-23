#include <iostream>
#include <math.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int min(int x, int y, int z) 
{
	return min(min(x, y), z);
}
/*** TOP DOWN ***/
int dp[100][100];
int edit_dist(string s1,string s2,int m,int n)
{
	if(n==0) return m;
	if(m==0) return n;
	
	if(dp[m][n] != -1 ) return dp[m][n];
	
	if(s1[m-1] == s2[n-1]){
		return edit_dist(s1, s2, m-1, n-1);
	} 
	dp[m][n] = 1+min(
		edit_dist(s1, s2, m-1, n),
		edit_dist(s1, s2, m, n-1),
		edit_dist(s1, s2, m-1, n-1)
	);
	return dp[m][n];
}
/** BUTTOMUP ***/

int Edit_Distance(string s1,string s2,int m,int n)
{
	int dp[m+10][n+10];
	
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			
			if(i == 0)
				dp[i][j] = j;
			else if(j == 0)
				dp[i][j] = i;
			else if(s1[i-1] == s2[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}else{
				dp[i][j] = 1+min(
					dp[i-1][j],
					dp[i][j-1],
					dp[i-1][j-1]
				);
			}
		}
	}
	return dp[m][n];
}



int main() {
	string s1,s2;
	
	cin>>s1>>s2;
	
//	getline(cin,s1);
//	getline(cin,s2);
	
	cout<<Edit_Distance(s1, s2, s1.length(), s2.length())<<endl;
	
	memset(dp, -1, sizeof(dp));
	cout<<edit_dist(s1, s2, s1.length(), s2.length())<<endl;
	
}