
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(1000);

void addedge(int u,int v,int direction){
    adj[u].push_back(v);
    
    // 0 means undirected
    if(direction == 0){
        adj[v].push_back(u);
    }
}

void print(int n){
    for(int i = 0; i < n; i++){
        cout<<i<<" -> ";

        for(int j = 0; j < adj[i].size(); j++){
            cout<< adj[i][j] <<" ";
        }
        cout<<endl;
    }
}

void bfs(int start) {
    vector<bool> visited(1000, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(auto neighbor : adj[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}


void recbfs(int start, vector<bool> &visited) 
{
   // Base case
    if(visited[start]) return;

    // Print the current node
    cout << start << " ";
    visited[start] = true;

    // For every node of the graph
    for(auto i : adj[start]) {
        recbfs(i, visited);
    }
}

int main(){
    
    int n;
    cout<<"Enter the number of nodes: "<<endl;
    cin>>n;

    int m;

    cout<<"Enter the number of edges: "<<endl;
    cin>>m;

    
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        addedge(u, v, 0);
    }

    // printing the graph

    print(n);

    cout << "BFS: ";
    bfs(0);

    cout << endl;

    cout << "Recursive BFS: ";
    vector<bool> visited(1000, false);
    recbfs(0, visited);


    return 0;

}