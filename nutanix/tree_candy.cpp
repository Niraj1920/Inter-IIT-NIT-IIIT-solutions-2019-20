#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> parent(n+1);
	vector<bool> visited(n+1,false);
	for(int i=2;i<=n;i++)
	{
		cin>>parent[i];
	}
	int pos1,pos2;
	cin>>pos1>>pos2;
	//vector<int> harry;
	//vector<int> ron;
	//harry.push_back(pos1);
	visited[pos1]=true;
	//ron.push_back(pos2);
	int h=1,r=0;
	while(pos1!=1)
	{
		//cout<<pos1<<endl;
		//harry.push_back(parent[pos1]);
		pos1=parent[pos1];
		visited[pos1]=true;
		h++;
	}
	while(pos2!=1)
	{
		if(!visited[pos2])
		{
			//ron.push_back(parent[pos2]);
			pos2=parent[pos2];	
			r++;
		}
		else
			break;
		
	}
	//sort(harry.begin(),harry.end());
	//sort(ron.begin(),ron.end());
	//vector<int> inter(n,0);
	//set_intersection(harry.begin(),harry.end(),ron.begin(),ron.end(),inter.begin());
	//int i=0;
	//while(inter[i]!=0)
	//	i++;6 4 1 1 3 3 3 6
	cout<<h<<" "<< r;
}