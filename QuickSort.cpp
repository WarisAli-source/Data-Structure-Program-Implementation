#include<iostream>
using namespace std;
//Quick Sort Algo
int Partition(int arr[],int s, int e)
{
		int pivot = arr[e];
		int pIndex = s;
		
		for(int i =s;i<e;i++)
		{
			if(arr[i]<pivot)
			{
				int temp = arr[i];
				arr[i] =arr[pIndex];
				arr[pIndex]= temp;	
				pIndex++;	
				
			}	
			
		}	
	int temp = arr[e];
	arr[e]=arr[pIndex];
	arr[pIndex] = temp;
		
	return pIndex;
}


void QuickSort(int arr[],int s,int e)
{
	if(s<e)
	{
		int p = Partition(arr,s,e);
		QuickSort(arr,s,(p-1)); //Recursive QuickSort for left partition
		QuickSort(arr,(p+1),e); //Recusive Quicksort for right partition
	}
	
	
	
}





int main(){
	int size =0;
	cout<<"Enter size of array: "<<endl;
	cin>>size;
	int myarray[size];
	cout<<"Enter "<<size<<"integers in array: "<<endl;
	for(int i;i<size;i++)
	{
		
		cin>>myarray[i];
	}
	cout<<"Before Sorting: "<<endl;
	for(int i;i<size;i++)
	{
		
		cout<<myarray[i]<<" "<<endl;
	}
	
	QuickSort(myarray,0,(size-1));
	
	cout<<"After Sorting";
	for(int i;i<size;i++)
	{
		
		cout<<myarray[i]<<" ";
	}
	
	
	
	return 0;
}
