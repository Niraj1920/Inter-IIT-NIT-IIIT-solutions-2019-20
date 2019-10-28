#include <bits/stdc++.h>
using namespace std;

class Graph{
    map<char, set<char>> adjList;
public:
    void addEdge(char u, char v,bool &dup, bool &child2){
        //search if u->v is already there

        auto it = adjList[u].find(v);
        if(it != adjList[u].end()){
            dup = true;
            //return;
        }
        //dup = false;
        if(adjList[u].size() == 2){
            child2 = true;
            //return;
        }
        
        adjList[u].insert(v);
    }
    
    void print(){
        for(auto i:adjList){
            cout<<i.first<<" --> ";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
    
    pair<bool, char> findroot(bool &multipleParent){
        map<char, int> m;
        for(auto i:adjList) m[i.first] = 0;
        
        for(auto i:adjList){
            char u = i.first;
            for(auto v:i.second){
                m[v]++;
            }
        }
        int count = 0;
        char root;
        for(auto p:m){
            if(p.second == 0){
                count++;
                root = p.first;
            }
            
            if(p.second > 1) multipleParent=true;
        }
        
        if(count > 1) return make_pair(true,root);
        return make_pair(false,root);
    }
    
    void dfs(char node, string &res){
        res += "("+string(1,node);
        for(auto v:adjList[node]){
            dfs(v,res);
        }
        res += ")";
    }
    
    bool cycledfs(char node, map<char, bool> &recStack, map<char, bool> &visited){
        visited[node] = true;
        recStack[node] = true;
        
        //visit neighbors
        for(auto v:adjList[node]){
            if(!visited[v] and cycledfs(v,recStack, visited)){
                return true;
            }
            else if(recStack[v])
                return true;
        }
        
        recStack[node] = false;
        return false;
    }
    
    bool isCycle(){
        map<char, bool> recStack;
        map<char, bool> visit;
        
        for(auto i: adjList){
            recStack[i.first] = false;
            visit[i.first] = false;
        }
        
        for(auto i:adjList){
            char u = i.first;
            bool ans = false;
            if(!visit[u])
                ans = cycledfs(u,recStack, visit);
            if(ans) return true;
        }
        return false;
    }
};

int main(){
    Graph g;
    
    string s;
    getline(cin,s);
    
    int i = 1, n = s.length();
    char u = s[1];
    char v = s[3];
    
    bool dup=false, child2=false, multipleParent=false;
    set<string> s1; //error set
    
    g.addEdge(u,v,dup,child2);
    if(dup) s1.insert("E2");
    if(child2) s1.insert("E1");
        
    int j = 3;
 
    while(i+6 < n and j+6 < n){
        u = s[i+6];
        v = s[j+6];
        
        dup = false; child2=false;
        
        g.addEdge(u, v, dup, child2);
        if(dup) s1.insert("E2");
        if(child2) s1.insert("E1");
        
        i +=6;
        j += 6;
    }
    if(g.isCycle()) s1.insert("E3");
    auto p = g.findroot(multipleParent);
    //multiple root
    if(p.first) s1.insert("E4");
    if(multipleParent) s1.insert("E5");
    
    if(s1.size()){
        cout<<*(s1.begin())<<endl;
        return -1;
    } 
   
    string res = "";
    g.dfs(p.second, res);
    
    cout<<res<<endl;
}

// (A,B) (A,C) (B,G) (C,H) (E,F) (B.D) (C,E)
// (5,6) (5,4) (4,8) (4,9) (6,7)

