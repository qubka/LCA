#include <iostream> 
#include <list> 
#include <stack> 
#include <limits.h> 

using namespace std; 
  
class Graph 
{ 
    int V;    
    list<int> *adj;
    
    public: 
        Graph(int V);   
        void addEdge(int u, int v); 
        int LCA(int u , int v);
        void getParent(int parent[], int Node);
        void DFS(int v);
    
    private:
        void DFS(int v, bool visited[]); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 

void Graph::addEdge(int u, int v) 
{ 
    adj[u].push_back(v);
}

void Graph::getParent(int parent[], int Node)
{       
    for(int n = 0; n < Node; n++) 
    {
        list<int>::iterator i;     
        for(i = adj[n].begin(); i != adj[n].end(); ++i)
        {
            if(*i == Node)
            {
                parent[Node] = n;
            }
        }
    }
}

int Graph::LCA(int u, int v)
{
    bool *visited = new bool[V]; 
    int *parent = new int[V];
    for(int i = 0; i < V; i++) 
    {
        visited[i] = false; 
        getParent(parent, i);
    }

    int lca;
    while(true)
    {
        visited[u] = true;
        if(u == *adj[0].begin()) // this is root!
        {
            break ; 
        }
        
        u = parent[u]; 
    }

    while(true)
    {
        if(visited[v])
        {
            lca = v;    
            break;  
        }
        
        v = parent[v]; 
    }
    
    return lca;
}

void Graph::DFS(int v) 
{ 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
    {
        visited[i] = false; 
    }
    
    DFS(v, visited); 
}

void Graph::DFS(int v, bool visited[]) 
{ 
    visited[v] = true; 
    cout << v << " "; 
  
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
    {
        if (!visited[*i]) 
        {
            DFS(*i, visited);
        }
    }
}

/*int main()
{
    Graph g(6); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(1, 2); 
    g.addEdge(2, 4); 
    g.addEdge(2, 5); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4); 
    g.addEdge(4, 5); 

    cout << "Following is DFS" " (starting from vertex 2) \n"; 
    g.DFS(2); 
}*/

#include "lca_test.cpp"
