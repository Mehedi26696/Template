
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;
    int n;
public:
     
    DisjointSet(int n){
        this->n = n;

        // 1- based indexing    
        parent.resize(n+1, 0);
        rank.resize(n+1, 0);
        
        for(int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
            

    }

    int findroot(int u){
        if(parent[u] == u)
            return u;
        return parent[u] = findroot(parent[u]);
    }

    void unionSet(int u, int v){
        int pu = findroot(u);
        int pv = findroot(v);
        if(pu == pv)
            return;
        if(rank[pu] > rank[pv])
            parent[pv] = pu;
        else if(rank[pu] < rank[pv])
            parent[pu] = pv;
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

int main(){
    DisjointSet ds(5);
    ds.unionSet(0, 2);
    ds.unionSet(4, 2);
    ds.unionSet(3, 1);
    
    if(ds.findroot(4) == ds.findroot(0))
        cout << "Yes\n";
    else
        cout << "No\n";
    
    if(ds.findroot(1) == ds.findroot(0))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}