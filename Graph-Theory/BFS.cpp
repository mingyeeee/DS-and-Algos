/* Mingye Chen 2021-02-14
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

vector<int> BFS(int src, int dst, UnweightedDigraph graph, int N){
    queue<int> node_queue;
    node_queue.push(src);
    vector<bool> visited(N, false);
    // index is the node and the value in the index is the parent node
    vector<int> parent_nodes(N, NULL);
}


int main(){
    vector<vector<int>> edge_def = 
    {
        {0,1}, {0,4}, {1,4}, {1,3}, {1,2}, {2,3}
    };
    UnweightedDigraph uwdigraph(edge_def, 5);
    uwdigraph.print_adj_list();
    return 1;
}
