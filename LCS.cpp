#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lcs(string s1,string s2,int n,int m){
	if(n == 0 || m==0)
		return 0;
	if(s1[n-1] == s2[m-1])
		return 1+lcs(s1,s2,n-1,m-1);
	else{
		return max(lcs(s1,s2,n,m-1),lcs(s1,s2,n-1,m));
	}
	

}
//optimal solution

int Lcs(string s1,string s2,int n,int m){ 
	
	int l[n+1][m+1];
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0 || j==0)
				l[i][j] = 0;
			else if(s1[i-1]==s2[j-1])
				l[i][j] = l[i-1][j-1]+1;
			else {
				l[i][j] = max(l[i-1][j],l[i][j-1]);
			}
		}
	}
	return l[n][m];
	
}

int main(int argc, char *argv[]) {
	
	string s1 = "AGGTAB";
	string s2 = "GXTXAYB";
	
	cout<<Lcs(s1,s2,s1.length(),s2.length())<<endl;
	
	return 0;	
}