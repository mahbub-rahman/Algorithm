#include <iostream>

using namespace std;
#define MAX 100
int n;
int m[MAX][MAX];
int s[MAX][MAX];
void Matrix_chain(int mat[])
{
	for(int i=1;i<=n;i++) m[i][i] = 0;
	
	for (int l = 2;l<=n;l++){
		for(int i = 1;i<=n-l+1;i++){
			int j = i+l-1;
			m[i][j] = 1<<28;
			for(int k=i;k<=j-1;k++){
				int q = m[i][k] + m[k+1][j] +mat[i-1]*mat[k]*mat[j];
				
				if(q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	} 
}


void print(int mat[] ,int i,int j)
{
	if(i == j){
		cout<<mat[i-1]<<" ";
	}else{
		cout<<"(";
		print(mat,i,s[i][j]);
		print(mat,s[i][j]+1, j );
		cout<<")";
	}
}

int main(int argc, char *argv[]) {
	
	int mat[] = {30,35,15,5,10,20,25};
	
	n = 6;
	Matrix_chain(mat);
	cout<< "Totall Cost : "<< m[1][6]<<endl;
	print(mat,1, 6);
}