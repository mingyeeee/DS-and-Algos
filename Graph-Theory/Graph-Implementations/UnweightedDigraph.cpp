/* Mingye Chen 2021-02-14
 * basic unweighted digraph using vectors and 
 */
#include <bits/stdc++.h>
using namespace std;

class UnweightedDigraph{
public:
    // adjacency list 
    vector<vector<int>> adj_list;
    UnweightedDigraph(vector<vector<int>> edge_def, int n_nodes){
        adj_list.resize(n_nodes);
        // populate adjacency lists 
        for(int i = 0; i < edge_def.size(); i++){
            adj_list[edge_def[i][0]].push_back(edge_def[i][1]);
            adj_list[edge_def[i][1]].push_back(edge_def[i][0]);
        }
    }
    // iterates through the adjacency list
    void print_adj_list(){
        for(int i = 0; i < adj_list.size(); i++){
            cout << "node: " << i << " linked to: ";
            for(int j = 0; j < adj_list[i].size(); j++)
                cout << adj_list[i][j] << " ";
            cout << endl;
        }
    }
};

int main(){
    // test case
    vector<vector<int>> edge_def = 
    {
        {0,1}, {0,4}, {1,4}, {1,3}, {1,2}, {2,3}
    };
    UnweightedDigraph uwdigraph(edge_def, 5);
    uwdigraph.print_adj_list();
    return 1;
}
