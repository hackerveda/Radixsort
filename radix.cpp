//radix sort
#include<iostream>
#include<math.h>
using namespace std;
static int k=9,n,d;
void CountSort(int A[],int g[])
{
	int B[20],C[20];
	for(int i=0;i<=k;i++)
		C[i]=0;
	for(int j=1;j<=n;j++)
		C[g[j]]=C[g[j]]+1;
	for(int i=1;i<=k;i++)
		C[i]=C[i]+C[i-1];
	for(int j=n;j>=1;j--)
	{
		B[C[g[j]]]=A[j];
		C[g[j]]=C[g[j]]-1;
	}
	for(int i=1;i<=n;i++)
		A[i]=B[i];
}

int main()
{
	int A[20],g[20];
	cout<<"Enter no. of digits :";cin>>d;
	//cout<<"Enter the range of numbers :";cin>>k;
	cout<<"Enter no. of elements :";cin>>n;
	cout<<"Enter the elements one by one :";
	for(int i=1;i<=n;i++)
		cin>>A[i];
	for(int i=1;i<=d;i++)
	{
		for(int j=1;j<=n;j++)
		{
			g[j]=(int(A[j]/pow(10,i-1)))%10;
		}
		CountSort(A,g);
		cout<<"\nPass "<<i<<":";
		for(int x=1;x<=n;x++)
			cout<<A[x]<<"\t";
	}

	cout<<"\nFinal array status after radix sort :\n";
	for(int i=1;i<=n;i++)
		cout<<A[i]<<"\t";
}
		
		

