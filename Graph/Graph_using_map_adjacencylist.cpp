
#include <bits/stdc++.h>
using namespace std;

class Graph
{   
    public:
    map<int, list<int>> adj;

    void addEdge(int u, int v , bool direction)
    {
        // direction = 0 means undirected 
        // direction = 1 means directed
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
         
    }

    void print(){
        for(auto i : adj){
            cout << i.first << " -> ";
            for(auto j : i.second){
                cout << j << " ";
            }
            cout << endl;
        }
    }

};

int main(){

    int n;
    cout<<"Enter the number of nodes: "<<endl;
    cin>>n;

    int m;

    cout<<"Enter the number of edges: "<<endl;

    cin>>m;

    Graph g;

    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        // creating an undirected graph
        g.addEdge(u, v, 0);
    }

    // printing the graph

    g.print();
    return 0;
}