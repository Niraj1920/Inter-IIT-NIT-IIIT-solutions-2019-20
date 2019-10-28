#include<bits/stdc++.h>
using namespace std;

bool find(vector<int> arr, int start, int end, int k)
{
	if(start<=end)
	{
		int mid=(start+end)/2;
		if(arr[mid]==k)
			return true;
		if(arr[mid]<k)
			return find(arr,mid+1,end,k);
		else
			return find(arr,start,mid-1,k);
	}
	return false;
}




int main()
{
	int n,k;
	cin>>n >> k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr.begin(),arr.end());
	int count=0;
	for(int i=0;i<n-1;i++)
	{
		if(find(arr,i+1,n-1,arr[i]+k))
			count++;
	}
	cout<<count;
	return 0;
}