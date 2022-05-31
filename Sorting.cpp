#include <iostream>
#include <cmath>
#define MAX 5
using namespace std;
class Sorting
{
	int temp;
	public:
		int ar[MAX];
		Sorting():temp(0){	}
		void setter()
		{
			for(int i=0;i<MAX;i++)
			{
				cout<<"Enter Element No."<<i+1<<": ";
				cin>>ar[i];
			}
		}
		void getter()
		{
			for(int i=0;i<MAX;i++)
			{
				cout<<ar[i]<<"  ";
			}
			cout<<endl;
		}
		void bubble_sort()
		{
			for(int i=0;i<MAX-1;i++)
			{
				for(int j=0;j<MAX-i;j++)
				if(ar[j]>ar[j+1])
				{
					//swapping
					temp=ar[j];
					ar[j]=ar[j+1];
					ar[j+1]=temp;
				}
			}
		}
		void selection_sort()
		{
			int minimum;
			for(int i=0;i<MAX-1;i++)
			{
				minimum=i;
				for(int j=i+1;j<MAX;j++)
				{
					if(ar[j]>ar[minimum])
					minimum=j;
					//now swaping
					temp=ar[j];
					ar[j]=ar[minimum];
					ar[minimum]=temp;
				}
			}
		}
		void insertion_sort()
		{
			int key,j;
			for(int i=1;i<MAX;i++)
			{
				key=ar[i];
				j=i-1;
				while(j>=0 && ar[j]>key)
				{
					ar[j+1]=ar[j];
					j=j-1;
					
				}
				ar[j+1]=key;
				getter();
			}
		}
		void merge_sort(int ar[],int,int);
		void merge(int ar[],int,int,int);
		void process()
		{
			int p=0,r=MAX-1;
			merge_sort(ar,p,r);
		}
};
void Sorting::merge_sort(int ar[],int p,int r)
{
	if(p<r)
	{
		int q=floor(p+r/2);
		merge_sort(ar,p,q);	
		merge_sort(ar,q+1,r);
		merge(ar,p,q,r);
	}
}
void Sorting :: merge(int ar[],int p,int q,int r)
{
	cout<<"Called";
	int n1,n2;
	n1=floor(MAX/2);
	n2=MAX-n1;
	int l[n1],rr[n2];
	for(int i=0; i<n1 ; i++)
	{
		l[i]=ar[i];
	}
	for(int i=n1;i<MAX;i++)
	{
		rr[i]=ar[i];
	}
	int i=0,j=0;
	for(int k=0;k<MAX;k++)
	{
		if(l[i]<=rr[j])
		{
			ar[k]=l[i];
			i++;
		}
		else
		{
			ar[k]=rr[j];
			j++;
		}
	}
	
}

int main()
{
	Sorting srt;
	int ch;
	do
	{
		cout<<"    Main Menu\n";
		cout<<"1. Bubble Sort\n";
		cout<<"2. Selection Sort\n";
		cout<<"3. Insertion sort\n";
		cout<<"4. Divide and conquer\n";
		cout<<"5. Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				srt.setter();
				srt.bubble_sort();
				cout<<"After Sorting: ";
				srt.getter();
				break;
			case 2:
				srt.setter();
				srt.selection_sort();
				cout<<"After Sorting: ";
				srt.getter();
				break;
			case 3:
				srt.setter();
				srt.insertion_sort();
				cout<<"After Sorting: ";
				srt.getter();
				break;
			case 4:
				srt.setter();
				void process();
				cout<<"After Sorting: ";
				srt.getter();
				break;
			case 5:
				exit(-1);
		}
	}while(1);
	
	return 0;
}
