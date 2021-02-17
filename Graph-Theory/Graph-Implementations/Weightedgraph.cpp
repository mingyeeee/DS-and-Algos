/* Mingye Chen 2021-02-14
 * basic weighted graph using adjacency list and vectors
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct WeightedEdge{
    int src, dst, weight;
} WeightedEdge;
class Weightedgraph{
public:
    vector<vector<pair<int,int>>> adj_list;
    Weightedgraph(vector<WeightedEdge> edge_def, int n_nodes){
        adj_list.resize(n_nodes);
        for(int i = 0; i < edge_def.size(); i++){
            adj_list[edge_def[i].src].push_back({edge_def[i].dst, edge_def[i].weight});
            adj_list[edge_def[i].dst].push_back({edge_def[i].src, edge_def[i].weight});
        }
    }
    void print_adj_list(){
        for(int i = 0; i < adj_list.size(); i++){
            cout << "node: " << i << " links ";
            for(int j = 0; j < adj_list[i].size(); j++){
                cout << adj_list[i][j].first << ",";
                cout << adj_list[i][j].second << " - ";
            }
            cout << endl;
        }
    }
};
int main(){
    vector<WeightedEdge> edge_def = 
    {
        {0,1,1}, {0,4,3}, {1,4,2}, {1,3,3}, {1,2,4}, {2,3,1}, {4,3,1}
    };
    Weightedgraph wgraph(edge_def, 5);
    wgraph.print_adj_list();
    return 1;
}
