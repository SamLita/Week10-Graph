#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>

class Graph {
private:
    int vertices; 
    std::vector<std::vector<int>> adjList;

public:
    
    Graph(int v) : vertices(v) {
        adjList.resize(v);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); 
    }

 
    void displayGraph() {
        for (int i = 0; i < vertices; ++i) {
            std::cout << "Node " << i << ": ";
            for (int neighbor : adjList[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << "\n";
        }
    }

   
    void dfsUtil(int node, std::vector<bool>& visited) {
        visited[node] = true;
        std::cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited);
            }
        }
    }

    
    void dfs(int start) {
        std::vector<bool> visited(vertices, false);
        std::cout << "DFS Traversal: ";
        dfsUtil(start, visited);
        std::cout << "\n";
    }

    
    void bfs(int start) {
        std::vector<bool> visited(vertices, false);
        std::queue<int> q;

        visited[start] = true;
        q.push(start);

        std::cout << "BFS Traversal: ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            std::cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        std::cout << "\n";
    }
};



#endif