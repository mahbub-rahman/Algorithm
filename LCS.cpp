#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/* TOP DOWN */
int lcs(string s1,string s2,int n,int m){
	if(n == 0 || m==0)
		return 0;
	if(s1[n-1] == s2[m-1])
		return 1+lcs(s1,s2,n-1,m-1);
	else{
		return max(lcs(s1,s2,n,m-1),lcs(s1,s2,n-1,m));
	}
	

}
/**   optimal solution  BUTTOM UP */
int l[100][100];

int Lcs(string s1,string s2,int n,int m){ 
	
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
void print_solution(string s,int i,int j)
{
	if(i==0 || j==0)
		return;
	if(l[i-1][j] == l[i][j]){
		print_solution(s, i-1, j);
	}
	else if(l[i][j-1] == l[i][j]){
		print_solution(s, i, j-1);
	}
	else{
		print_solution(s, i-1, j-1);
		cout<<s[i-1];
	}
}

int main() {
	
	string s1 = "AGGTAB";
	string s2 = "GXTXAYB";
	
	cout<<Lcs(s1,s2,s1.length(),s2.length())<<endl;
	
	print_solution(s1, s1.length(), s2.length());
	
	return 0;	
}
