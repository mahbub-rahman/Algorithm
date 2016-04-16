#include <iostream>
#include <algorithm>

using namespace std;

void inSertion(int arr[],int n)
{
	for(int i = 1 ;i <n;i++){
		
		int j = i;
		int toinsert = arr[i];
		while(j>0 && arr[j-1] > toinsert){
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = toinsert;
	}
}
/** --------Recursive Insertion----------- */

void insertsionsort(int A[],int i,int n)
{
	if(i >= n)
		return;
		
		int j=i;
		int key = A[i];
		
		while(j>0 && A[j-1] > key){
			A[j] = A[j-1];
			j--;
		}
		A[j] = key;
		
		insertsionsort(A, ++i, n);
		
}


void Selection(int A[],int n)
{
	for(int i=0;i<n;i++){

		int min = i;
		
		for(int j=i;j<n;j++){
			if(A[min] > A[j]){
				min = j;
			}
		}
		swap(A[min],A[i]);
	}	
}

void Bubble(int A[],int n)
{
	for(int i=0;i<n;i++){
		
		for(int j=0;j<n-i-1;j++){
			if(A[j] > A[j+1]){
				swap(A[j],A[j+1]);
			}
		}
	}
}

/**......... Marge Sort........*/
void marge(int *l,int *r,int *A,int n1,int n2)
{
	int i = 0;
	int j = 0;
	int k = 0;
	
	while(i<n1 && j<n2){
		
		if(l[i] <= r[j]){
			A[k++] = l[i];
			i++;
		}else{
			
			A[k++] = r[j];
			j++;
		}
	}
	
	while(i<n1){
		A[k++] = l[i++];
	}
	while(j<n2){
		A[k++] = r[j++];
	}
		
}

void margeSort(int *A,int n)
{
	if(n<2) return ;
	int *L,*R;
    int mid = n/2;

	L = new int[mid]; // in c++ pointer memory allocation
	R = (int *) malloc(sizeof(int)*n-mid); // in c pointer memory allocation
	
	for(int i=0;i<mid;i++){
		L[i] = A[i];
	}
	for(int i=mid;i<n;i++){
		R[i-mid] = A[i];
	}
	
	margeSort(L, mid);
	margeSort(R, (n-mid));
	marge(L,R,A,mid,n-mid);
	free (L);
	free (R);
	
}
/**......... Marge Sort........*/

/**......... Quick Sort........*/

int Partition(int *A,int start,int end)
{
	int index = start;
	int pivot = A[end];
	
	for(int i=start;i<end;i++){
		
		if(A[i] <= pivot){
			swap(A[i],A[index]);
			index++;
		}
	}
	swap(A[end],A[index]);
	
	return index;
}


void QuickSort(int *A,int start,int end)
{
	if(start < end){
		int index = Partition(A, start, end);
		
		QuickSort(A, start, index-1);
		QuickSort(A, index+1, end);
		
	}
}
/**......... Quick Sort........*/

int main(int argc, char *argv[]) {
	
	int A[] = {33,1,44,5,88,89,69};
	
	//inSertion(A, 7);

	//Selection(A, 7);
	
	//Bubble(A, 7);
	
	//margeSort(A, 7);
	QuickSort(A, 0, 7);
		
	for(int i=0;i<7;i++)cout<<A[i]<<" ";
	cout<<endl;
		
	return 0;
	
}