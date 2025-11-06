#include<iostream>
#include<vector>
#include<list>
using namespace std;

void createEdge(vector<list<int>> &adjList, int src, int dest){
    adjList[src].push_back(dest);
}

void dfs(vector<list<int>> &adjList, int vertex, vector<bool> &visited){
    visited[vertex] = true;
    cout << vertex << " ";
    for(int neighbor : adjList[vertex]){
        if(!visited[neighbor]){
            dfs(adjList, neighbor, visited);
        }
    }
}

int main(){
    vector<list<int>> adjList(5);
    createEdge(adjList, 0, 1);
    createEdge(adjList, 0, 4);
    createEdge(adjList, 1, 2);
    createEdge(adjList, 1, 3);
    createEdge(adjList, 1, 4);
    createEdge(adjList, 2, 3);
}