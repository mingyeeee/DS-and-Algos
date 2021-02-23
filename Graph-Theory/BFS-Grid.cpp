/* Mingye Chen 2021-02-23
 * BFS on a grid
 */
#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

// input array
// S - start | E - end | '.' - empty cell | '#' - blocked cell
array<array<char,6>,5> grid = 
{{
    {'S','.','#','.','#','.'},
    {'.','.','.','.','.','.'},
    {'.','#','#','#','#','.'},
    {'.','.','.','#','#','.'},
    {'#','.','.','E','.','.'}
}};

int numRows = grid.size();
int numCols = grid[0].size();
int startRow = 0;
int startCol = 0;

// direction vectors
array<int, 4> dr = {-1, 1, 0, 0};
array<int, 4> dc = {0, 0, 1, -1};

int findPath(){
    // initialized with all false values
    array<array<char,6>,5> visited = {{false}};
    int moveCount = 0;
    int nodesLeftInLayer = 1;
    int nodesInNextLayer = 0;
    bool reachedEnd = false;

    queue<int> rowQ, colQ;
    rowQ.push(startRow);
    colQ.push(startCol);
    visited[startRow][startCol] = true;

    while(rowQ.size() > 0){
        int currentRow = rowQ.front();
        rowQ.pop();
        int currentCol = colQ.front();
        colQ.pop();
        
        // if we reached the end denoted by E
        if(grid[currentRow][currentCol] == 'E'){
            reachedEnd = true;
            break;
        }
        // Explore if all neighbours if end is not reached
        for(int i = 0; i < 4; i++){
            // Add direction vectors which dictate movement to the neighbouring cells/nodes
            int nextRow = currentRow + dr[i];
            int nextCol = currentCol + dc[i];

            // Skip if cell is out of bounds
            if(nextRow < 0 || nextCol < 0) continue;
            if(nextRow >= numRows || nextCol >= numCols) continue;

            // Skip if already visited or is a blocked cell
            if(visited[nextRow][nextCol]) continue;
            if(grid[nextRow][nextCol] == '#')continue;

            // enqueue to visit later and mark as visited
            rowQ.push(nextRow);
            colQ.push(nextCol);
            // debug
            //cout << "adding to the queue: " << nextRow << ", " << nextCol << endl;
            visited[nextRow][nextCol] = true;
            nodesInNextLayer++;
        }
        // Track number of steps required to get to exit
        nodesLeftInLayer--;
        // Will increment moveCount after every layer of nodes it visits
        if(nodesLeftInLayer == 0){
            nodesLeftInLayer = nodesInNextLayer;
            nodesInNextLayer = 0;
            moveCount++;
        }
    }

    if(reachedEnd)
        return moveCount;
    return -1;
}

int main(){
    int shortestPath = findPath();
    cout << shortestPath << endl;
    return 1;
}
