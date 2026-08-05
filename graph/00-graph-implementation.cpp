#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;


class Graph{
    public:
    unordered_map<int,list<int>> adj;
    void addEdge(int u,int v,bool direction){
        // direction=0 --> undirected graph
        // direction=1 --> directed graph

        // create an edge between u and v
        adj[u].push_back(v);
        if (direction==0){
            adj[v].push_back(u);
        }
    }
    void printAdjList(int nodes){
        for (int i=0;i<nodes;i++){
            cout<<i<<"--> ";
            for (auto j: adj[i]){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};


int main(){

    int n;
    cout<<"Enter number of Nodes: ";
    cin>>n;
    int m;
    cout<<"Enter number of Edges: ";
    cin>>m;
    Graph g;
    for (int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        // creating an undirected graph
        g.addEdge(u,v,0);
    }
    // printing graph
    g.printAdjList(n);
    
    return 0;
}