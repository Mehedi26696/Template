
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mat (100, vector<int>(100, 0));

void addEdge(int i,int j)
{
    mat[i][j] = 1;
    mat[j][i] = 1;  // for undirected graph
}

void displayMatrix(int n )
{
     
    for (int i = 0; i <n ; i++)
    {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    
     int n;
    cout<<"Enter the number of nodes: "<<endl;
    cin>>n;

    int m;

    cout<<"Enter the number of edges: "<<endl;

    cin>>m;

    // vector<vector<int>> mat(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge( u, v);
    }

    cout << "Adjacency Matrix Representation" << endl;
    displayMatrix(n);

    return 0;
}