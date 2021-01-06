#include<iostream>
using namespace std;

//merge function
void merge(int arr[],int l,int m,int r)
{
	int i=l;  ///Starting Index for left sub array
	int j=m+1; //Starting index for right sub array
	int k=l; // Starting index for temporary array
	int temp[5];
	
	while(i<=m && j<=r)
	{
		if(arr[i]<=arr[j])
		{
			temp[k]=arr[j]; // arr[i] is smaller than arr[j]
			i++;
			k++;
		}
		else
		{
			temp[k]=arr[j]; // arr[j] is smaller than arr[i]
			j++;
			k++;	
		}
	}
	while(i<=m)
	{
		temp[k]=arr[i];
		i++;
		k++;
	}
	while(j<=r)
	{
		temp[k]=arr[j];
		j++;
		k++; 
	}
	
	for(int s=l;s<=r;s++)
	{
		arr[s]=temp[s];	
	}
}





//merge Sort function
void mergeSort(int arr[],int l,int r)
{
	if(l<r)
	{
		int m =(l+r)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
		
		
	} 
	
	
}



int main(){
	
	cout<<"Enter 5 Elements in the Array: "<<endl;
	int myarr[5];
	for(int i=0;i<5;i++)
	{
		cin>>myarr[i];	
	}
	cout<<"Before Merge Sort: \n"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<myarr[i]<<" ";	
	}
	//mergesort function call
	mergeSort(myarr,0,4);
	
	cout<<endl<<"After Merge Sort: \n"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<myarr[i]<<" ";	
	}

	
	return 0;
}
