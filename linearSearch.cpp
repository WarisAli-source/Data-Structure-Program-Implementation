#include<iostream>
using namespace std;
void linearSearch(int a[],int n)
	{
		int temp=-1;
		for(int i=0;i<5;i++){
			if(a[i]==n){
				cout<<"Element Found at position: "<<i+1<<endl;
				break;
			}
			
			
		}
		if(temp==-1)
		{
			cout<<"No element Found"<<endl;
		}
	
	}

int main(){
	int j,i;
	cout<<"Enter the Number of values for Array\n";
	cin>>j;
	int arr[j];
	cout<<"Enter"<<6<<" Digits for the Array\n";
	for(int i=0;i<j;i++)
	{
		cin>>arr[i];
	}
	cout<<"Please enter an element to search"<<endl;
	int num;
	cin>>num;
	linearSearch(arr,num);
	
	
	
	return 0;
}
