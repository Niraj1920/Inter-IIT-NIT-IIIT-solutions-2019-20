/*
There are given n ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to 
sum of their lengths. We need to connect the ropes with minimum cost.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minCost(vector<int> ropes){
    priority_queue <int, vector<int>, greater<int>> pq;
    for(int i=0; i<ropes.size(); i++){
        pq.push(ropes[i]);
    }
    int cost = 0;
    while(pq.size() > 1){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        cost += x + y;
        pq.push(x+y);
    }
    return cost;
}
int main()
{
    int n;
    cin>>n;
    vector<int> ropes(n, 0);
    for(int i=0; i<n; i++){
        cin>>ropes[i];
    }
    int cost = minCost(ropes);
    cout<<cost<<endl;
    return 0;
}
