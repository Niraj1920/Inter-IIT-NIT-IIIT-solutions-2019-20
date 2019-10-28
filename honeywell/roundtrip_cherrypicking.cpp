#include<bits/stdc++.h>
using namespace std;
#define MAX 100


int cal(int grid[][MAX], int r1, int c1, int r2, int c2)
{
	int ans=0;
	if(r1==r2 && c1==c2)
	{
		if(grid[r1][c2]==1)
			ans++;
		return ans;
	}
	if(grid[r1][c1]==1)
		ans++;
	if(grid[r2][c2]==1)
		ans++;
	return ans;
}

bool check(int r1, int c1, int r2, int c2, int n, int m, int grid[][MAX])
{
	if(r1<n && r2<n && c1<m && c2<m && grid[r1][c1]!=-1 && grid[r2][c2]!=-1)
		return true;
	else
		return false;
}

int max_cherry(int n, int m, int grid[][MAX], int dp[][MAX][MAX],int r1, int c1, int r2)
{
	int c2 = r1+c1-r2;
	if(r1==n-1 && c1==m-1 && r2==n-1 && c2==m-1)
		return 0;
	if(r1>=n || c1>=m || r2>=n || c2>=m)
		return INT_MIN;
	if(dp[r1][c1][r2]!=-1)
		return dp[r1][c1][r2];
	int ch1=INT_MIN,ch2=INT_MIN, ch3=INT_MIN,ch4=INT_MIN;
	//path1-right, path2-right
	if(check(r1,c1+1,r2,c2+1,n,m,grid))
		ch1=cal(grid,r1, c1+1,r2,c2+1) + max_cherry(n,m,grid,dp,r1,c1+1,r2);
	//path1-right,path2-down
	if(check(r1,c1+1,r2+1,c2,n,m,grid))
		ch2=cal(grid,r1, c1+1,r2+1,c2) + max_cherry(n,m,grid,dp,r1,c1+1,r2+1);
	//path1-down,path2-right
	if(check(r1+1,c1,r2,c2+1,n,m,grid))
		ch3=cal(grid,r1+1, c1,r2,c2+1) + max_cherry(n,m,grid,dp,r1+1,c1,r2);
	//path1-down,path2-down
	if(check(r1+1,c1,r2+1,c2,n,m,grid))
		ch4=cal(grid,r1+1, c1,r2+1,c2) + max_cherry(n,m,grid,dp,r1+1,c1,r2+1);
	return dp[r1][c1][r2]=max(ch1,max(ch2,max(ch3,ch4)));

}


int solver(int n, int m, int grid[][MAX])
{
	int ans=0;
	if(grid[0][0]==-1 || grid[n-1][m-1]==-1)
		return -1;
	if(grid[0][0]==1)
	{
		grid[0][0]=0;
		ans++;
	}
	if(grid[n-1][m-1]==1)
	{
		grid[n-1][m-1]=0;
		ans++;
	}
	int dp[MAX][MAX][MAX];
	memset(dp,-1,sizeof dp);
	ans+=max_cherry(n,m,grid,dp,0,0,0);
	return ans;
}



int main()
{
	int n = 5, m = 5; 
  
    int grid[MAX][MAX] = { 
        { 0, 1, 0, 1, 0 }, 
        { 1, -1, -1, -1, 0 }, 
        { 1, 0, 1, 0, 1 }, 
        { 0, -1, -1, -1, 1 }, 
        { 0, 1, 0, 1, 0 } 
    }; 
    cout<<solver(n,m,grid)<<endl;
	return 0;
}