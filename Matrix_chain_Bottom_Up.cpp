#include <iostream>

using namespace std;
#define MAX 100

int m[MAX][MAX];
int s[MAX][MAX];
void Matrix_chain(int mat[],int n)
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
					//cout<<"m["<<i<<"]"<<"["<<j<<"] = "<<q<<endl;
					s[i][j] = k;
					//cout<<"s["<<i<<"]"<<"["<<j<<"] = "<<k<<endl;
				}
			}
		}
	} 
}


void print_order(int i,int j)
{
	if(i == j){
		cout<<"A"<<i<<" ";
	}else{
		cout<<"(";
		print_order(i,s[i][j]);
		print_order(s[i][j]+1, j );
		cout<<")";
	}
}

int main() {
	
//	int mat[] = {30,35,15,5,10,20,25};
	int mat[] = {5,10,3,12,5,50,6}; 
	

	Matrix_chain(mat,6);
	cout<< "Totall Cost : "<< m[1][6]<<endl;
	print_order(1, 6);
}
