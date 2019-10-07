/*
You are given a 2D grid. each cell contains either 0 or 1. 0 means the cell is empty 1 means there is a tower on that cell. Each tower 
has height 1. Find max water you can store in the grid. Water can be stored in empty cell if they are surrounded by tower on all sides.
IF a empty cell is connected to edge of grid then water will flow out

Input
0110
1011
1001
1110

Output:
3

*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> &grid, int i, int j){
    int n = grid.size();
    if(i>=0 && i<n && j>=0 && j<n)  return true;
    return false;
}
void dfs(vector<vector<int>> &grid, int i, int j){
    if(grid[i][j] == 1) return;
    else{
        grid[i][j] = 1;
        if(isValid(grid, i, j+1))   dfs(grid, i, j+1);
        if(isValid(grid, i-1, j))   dfs(grid, i-1, j);
        if(isValid(grid, i, j-1))   dfs(grid, i, j-1);
        if(isValid(grid, i+1, j))   dfs(grid, i+1, j);
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> grid(n, vector<int>(n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    for(int j=0; j<n; j++){
        dfs(grid, 0, j);
    }
    for(int i=1; i<n; i++){
        dfs(grid, i, n-1);
    }
    for(int j=n-2; j>=0; j--){
        dfs(grid, n-1, j);
    }
    for(int i=n-2; i>=0; i--){
        dfs(grid, i, 0);
    }
    int trap = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 0) trap++;
        }
    }
    cout<<trap<<endl;
    return 0;
}
