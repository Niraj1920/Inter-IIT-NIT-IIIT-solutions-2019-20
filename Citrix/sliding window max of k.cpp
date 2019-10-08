/*
Sliding Window Maximum (Maximum of all subarrays of size k)
Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.
Examples :

Input: arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3
Output: 3 3 4 5 5 5 6
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void max_in_K(int ar[], int n, int k){
    deque<int> qu;
    vector<int> ans;
    qu.push_back(0);
    for(int i=1; i<k; i++)
    {
        if(ar[i]<ar[qu.back()])
            qu.push_back(i);
        else
        {
            while(!qu.empty() and ar[i]>=ar[qu.back()])
                qu.pop_back();
            qu.push_back(i);
        }
            
    }
    
    for(int i=k; i<n; i++)
    {
        //cout<<ar[qu.front()]<<endl;
        ans.push_back(ar[qu.front()]);
        while(qu.front()<=i-k)
            qu.pop_front();
        if(ar[i]<ar[qu.back()])
            qu.push_back(i);
        else
        {
            while(!qu.empty() and ar[i]>=ar[qu.back()])
                qu.pop_back();
            qu.push_back(i);
        }
        
    }
    //cout<<ar[qu.front()]<<endl;
    ans.push_back(ar[qu.front()]);
    //cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i];
}

int main()
{
    int n, k;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }
    cin>>k;
    max_in_K(ar, n, k);
    return 0;
}
