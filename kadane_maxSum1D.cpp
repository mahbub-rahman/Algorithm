#include <iostream>
#include <algorithm>
using namespace std;
int maxsum(int arr[],int size)
{
	long long max_so_far=arr[0];
	long long curr_max = arr[0];
	for(int i=1;i<size;i++){
		curr_max = arr[i]+curr_max  < arr[i] ? arr[i] : arr[i]+curr_max;
		max_so_far = max(max_so_far , curr_max);
	}
	return max_so_far;
}

int main(int argc, char *argv[]) {
	int ar[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	
	cout<<maxsum(ar, 8)<<endl;
}