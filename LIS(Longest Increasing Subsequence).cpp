#include <iostream>

using namespace std;

int T[100]; // conuntying len
int s[100]; // finding actual index of element
int Lis( int arr[], int n )
{
 	int max_len = 0;

	for (int i = 0; i < n; i++ ){
		T[i] = 1;
		s[i] = i;
	}

	for (int i = 1; i < n; i++ )
		for (int j = 0; j < i; j++ )
		if ( arr[i] > arr[j] && T[i] < T[j] + 1){
				T[i] = T[j] + 1;
				s[i] = j;
		}

	for (int i = 0; i < n; i++ )
		if ( max_len < T[i] )
			max_len= T[i];

	return max_len;
}
void print_solution(int arr[],int n)
{
		int maxIndex = 0;
			for(int i=0; i < n; i++){
				if(T[i] > T[maxIndex]){
					maxIndex = i;
				}
			}

			//lets print the actual solution
			int t = maxIndex;
			int newT = maxIndex;
			do{
				t = newT;
				cout<<arr[t] <<" ";
				newT = s[t];
			}while(t != newT);

			cout<<endl;


}

int main() {

	int arr[100];
	int n;

	cin>>n;

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<Lis(arr,n)<<endl;
	print_solution(arr, n);
/*
	int arr[] = {10,22,5,33,8,9,21,50,41,60,80,99};
	cout<<T(arr,12)<<endl;
	print(arr, 12);

	*/

return 0;

}
