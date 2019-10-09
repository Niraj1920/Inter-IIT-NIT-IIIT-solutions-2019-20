/*
Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :

A : [  1 1 1
       0 1 1
       1 0 0 
    ]

Output : 4 

*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxAreaofHist(vector<int> &A){
    int n = A.size(), i = 0, max_area = INT_MIN, area = 0;
    stack<int> s;
    while(i < n){
        if(s.empty() || A[i] >= A[s.top()]) s.push(i++);
        else{
            int temp = s.top();
            s.pop();
            area = (s.empty() ? i : i-s.top()-1) * A[temp];
            if(max_area < area) max_area = area;
        }
    }
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        area = (s.empty() ? i : i-s.top()-1) * A[temp];
        if(max_area < area) max_area = area;
    }
    return max_area;
}

int main()
{
    int m, n;
    cin>>m>>n;
    vector<vector<int>> A(m, vector<int> (n, 0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>A[i][j];
        }
    }
    int maxArea = INT_MIN;
    int area = maxAreaofHist(A[0]);
    //cout<<area<<endl;
    for(int i=1; i<m; i++){
        for(int j=0; j<n; j++){
            if(A[i][j] != 0)    A[i][j] += A[i-1][j];
        }
        maxArea = max(maxArea, maxAreaofHist(A[i]));
    }
    cout<<maxArea<<endl;
    return 0;
}
