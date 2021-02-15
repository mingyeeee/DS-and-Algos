/* Mingye Chen 2021-02-15
 * Breadth First Search with unweighted digraph
 */
#include <bits/stdc++.h>
using namespace std;

class UnweightedDigraph{
public:
    vector<vector<int>> adj_list;
    UnweightedDigraph(vector<vector<int>> edge_def, int n_nodes){
        adj_list.resize(n_nodes);
        for(int i = 0; i < edge_def.size(); i++){
            adj_list[edge_def[i][0]].push_back(edge_def[i][1]);
            adj_list[edge_def[i][1]].push_back(edge_def[i][0]);
        }
    }
    void print_adj_list(){
        for(int i = 0; i < adj_list.size(); i++){
            cout << "node: " << i << " linked to: ";
            for(int j = 0; j < adj_list[i].size(); j++)
                cout << adj_list[i][j] << " ";
            cout << endl;
        }
    }
};

// src - source node | dst - destination node | N - number of nodes in the graph 
vector<int> BFS(int src, int dst, UnweightedDigraph& graph, int N){
    queue<int> node_queue;
    node_queue.push(src);
    // visited list
    vector<bool> visited(N, false);
    visited[src] = true;
    // index is the node and the value in the index is the parent node
    // -1 as null, NULL is 0 which gets confused with a purposeful 0
    vector<int> parent_nodes(N, -1);
    //cout << "starting loop" << endl;
    while(!node_queue.empty()){
        //get node from queue
        int node = node_queue.front();
        //cout << "popping " << node << endl;
        node_queue.pop();
        //iterate through all neighbours
        for(int i = 0; i < graph.adj_list[node].size(); i++){
            int connectedNode = graph.adj_list[node][i];
            //cout << "checking neighour node: " << connectedNode << endl;
            if(!visited[connectedNode]){
                node_queue.push(connectedNode);
                //cout << "adding node: " << connectedNode << endl;
                visited[connectedNode] = true;
                parent_nodes[connectedNode] = node;
            }
        }
    }
    // reconstructing the path backwards from dst
    vector<int> path;
    // -1 instead of NULL as NULL = 0 
    for(int i = dst; i != -1; i = parent_nodes[i])
        path.push_back(i);

    // reverse path -> src to dst
    reverse(path.begin(), path.end());
    // check if src is included in the path which indicate that a path exists
    if(path[0] == src)
        return path;
    // if no path exist
    return {};
}


int main(){
    vector<vector<int>> edge_def = 
    {
        {0,1}, {1,2}, {2,4}, {2,3}, {1,3}, {5,6}
    };
    UnweightedDigraph uwdigraph(edge_def, 7);
    uwdigraph.print_adj_list();
    
    // testing BFS
    vector<int> path = BFS(1,6,uwdigraph,7);
    // check if path output exists
    if(path.size() == 0){
        cout << "no path exists" << endl;
        return -1;
    }
    // else print path
    cout << "path";
    for(int i = 0; i < path.size(); i++){
        cout << " -> " << path[i];
    }
    return 1;
}
