#include <iostream> 
#include <list> 
#include <stack> 
#include <limits.h> 

#include "lca_test.cpp"

using namespace std; 
  
class AdjListNode 
{ 
    int v;
    
    public: 
    
        AdjListNode(int _v)  
        { 
            v = _v;  
        } 
        
        int getV()       
        {  
            return v;  
        } 
}; 
  
class Graph 
{ 
    int V;    
    list<AdjListNode> *adj;
    
    public: 
        Graph(int V);   
        void addEdge(int u, int v); 
        int LCA(int u , int v);
        void getParent(int parent[], int Node);
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<AdjListNode>[V]; 
} 

void Graph::addEdge(int u, int v) 
{ 
    AdjListNode node(v); 
    adj[u].push_back(node);
}

void Graph::getParent(int parent[], int Node)
{       
    for(int n = 0; n < Node; n++) 
    {
        list<AdjListNode>::iterator i;     
        for(i = adj[n].begin(); i != adj[n].end(); ++i)
        {
            AdjListNode node = *i; 
            if(node.getV() == Node)
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
        visited[u] = true; AdjListNode node = *adj[0].begin();
        if(u == node.getV())
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