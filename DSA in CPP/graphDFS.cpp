#include<iostream>
#include<list>
#include<vector>
using namespace std;
class graph{
    public:
    vector<list<int>> adjList;

    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }
    void dfs(vector<bool> vis, int vertex) {
        cout << vertex << " ";
        vis[vertex] = true;

        for(int v : adjList[vertex]) {
            if(!vis[v]){
                dfs(vis, v);
            }
        }
        cout<< endl;
    }
};

int main(){
    graph g;
    int V = 5; // Number of vertices
    g.adjList.resize(V);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    vector<bool> visited(V, false);
    cout << "Depth First Traversal starting from vertex 0:" << endl;
    g.dfs(visited, 0);

    return 0;
}