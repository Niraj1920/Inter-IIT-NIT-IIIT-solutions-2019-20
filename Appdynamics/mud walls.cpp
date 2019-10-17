#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> loc(n);
	vector<int> height(n);

	for(int i=0;i<n;i++)
		cin>>loc[i];
	for(int i=0;i<n;i++)
		cin>>height[i];

	int maximum=INT_MIN;
    int diff = 0;
	for(int i=0;i<n;i++)
	{
		diff = loc[i] - loc[i-1];
		int maxi = max(height[i], height[i-1]);
		int mini = min(height[i], height[i-1]);
		int incr = (mini - maxi + diff)/2;
		maximum = max(maximum, incr + maxi);
	}

	cout<<"maximum:"<<maximum<<endl;
	return 0;

}
