#include <iostream>
#include <string>
using namespace std;
int r[20],s[20];
// Bottom up.....
void Extended_RodCut(int p[],int n)
{
	for(int i=1;i<=n;i++){
		int q = -(1<<28);
		for(int j = 1;j<=i;j++){
			if(q < p[j]+r[i-j]){
				q = p[j]+r[i-j];
				s[i] = j; 
			}
		}
		r[i] = q;
	}
}
void print(int n)
{
	while(n>0){
		cout<<s[n]<<" ";
		n = n-s[n];
	}
}
int main(int argc, char *argv[]) {
	int arr[] = {0,1, 5, 8, 9, 10, 17, 17, 20};
	
	int n;
	cin>>n;
	memset(r, 0, sizeof(r));
	memset(s, 0, sizeof(s));
	
	Extended_RodCut(arr, n);
	print(n);
	cout<<endl<<r[n]<<endl;
	
	return 0;
}