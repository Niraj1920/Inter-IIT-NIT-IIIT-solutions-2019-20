#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void angryAnimals(vector<int> a, vector<int> b, int n){
    int enemies = a.size();
    vector<priority_queue<int>> e(n+1);
    for(int i=0; i<enemies; i++){
        if(a[i] >= b[i]){
            e[a[i]].push(b[i]);
        }
        else{
            e[b[i]].push(a[i]);
        }
    }
    int count = 0;
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(!e[i].empty()){
            while(!e[i].empty() && !q.empty() && e[i].top() >= q.front() && e[i].top() <= q.back()){
                if(e[i].top() == q.front()){
                    q.pop();
                    e[i].pop();
                    count += q.size();
                }
                else{
                    q.pop();
                    count += q.size();
                }
            }
            q.push(i);
            count++;
        }
        else{
            q.push(i);
            count++;
        }
    }
    count += q.size()*(q.size()-1)/2;
    cout<<count<<endl;
    return;
}
int main()
{
    
    int n, enemies;
    cin>>n>>enemies;
    vector<int> a(enemies, 0), b(enemies, 0);
    for(int i=0; i<enemies; i++){
        cin>>a[i];
    }
    for(int i=0; i<enemies; i++){
        cin>>b[i];
    }
    
    angryAnimals(a, b, n);
    return 0;
}
