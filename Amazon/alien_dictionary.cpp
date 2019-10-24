#include<bits/stdc++.h>
using namespace std;

void dfs(stack<int> &s,vector<vector<int>> adj, vector<bool> &visited, int v)
{
	visited[v]=true;
	for(auto i:adj[v])
	{
		if(!visited[i])
			dfs(s,adj,visited,i);
	}
	s.push(v);
}


void topological_sort(vector<vector<int>> adj,int alpha)
{
	stack<int> s;
	vector<bool> visited(alpha,false);
	for(int i=0;i<alpha;i++)
	{
		if(visited[i]==false)
			dfs(s,adj,visited,i);
	}
	while(!s.empty())
	{
		cout<<(char)('a'+s.top())<<"->";
		s.pop();
	}
}

void alliendict(vector<string> dict, int n, int alpha)
{
	vector<vector<int>> adj(alpha);
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<min(dict[i].length(),dict[i+1].length());j++)
		{
			if(dict[i][j]!=dict[i+1][j])
			{
				adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
				//break;
			}
		}
	}
	topological_sort(adj,alpha);
}




int main()
{
	int n;
	cin>>n;
	vector<string> diction(n);
	//cout<<"hello";
	for(int i=0;i<n;i++)
		cin >> diction[i];
	unordered_set<char> alpha;
	cout<<"hi";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j < diction[i].length();j++)
			if(alpha.find(diction[i][j])==alpha.end())
				alpha.insert(diction[i][j]);
	}
	int c_alpha=alpha.size();
	cout<<c_alpha;
	alliendict(diction,n,c_alpha);
	return 0;
}