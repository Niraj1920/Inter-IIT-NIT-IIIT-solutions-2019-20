#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void maxofminK(vector<int> ar, int k){
    int n = ar.size();
   // vector<int> ans;
    deque<int> q;
    q.push_back(0);
    for(int i=0; i<k; i++){
        if(ar[i] >= ar[q.back()]){
            q.push_back(i);
        }
        else{
            while(!q.empty() && ar[i] <= q.front()){
                q.pop_front();
            }
            q.push_back(i);
        }
    }
    int maxk = INT_MIN;
    for(int i=k; i<n; i++){
        maxk = max(maxk, ar[q.front()]);
        //ans.push_back(ar[q.front()]);
        while(q.front() <= i-k){
            q.pop_front();
        }
        if(ar[i] >= ar[q.back()]){
            q.push_back(i);
        }
        else{
            while(!q.empty() && ar[i] <= q.front()){
                q.pop_front();
            }
            q.push_back(i);
        }
    }
    // for(int i=0; i<ans.size(); i++)
    //     cout<<ans[i]<<" ";
        
        cout<<endl<<maxk<<endl;
}
int main()
{
    
    int n, k;
    cin>>n>>k;
    vector<int> ar(n, 0);
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }
    maxofminK(ar, k);
    return 0;
}
