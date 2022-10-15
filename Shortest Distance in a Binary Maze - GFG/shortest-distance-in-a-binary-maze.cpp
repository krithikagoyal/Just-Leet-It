//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

    

    bool isSafe(int row, int col, int n , int m){

        if(row >= 0 and col >= 0 and row < n and col < m){

            return true;

        }

        return false;

    }

    

  public:

    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,

                     pair<int, int> destination) {

        // same s and d

        if(source == destination) return 0;

        int n = grid.size();

        int m = grid[0].size();

        //bfs

        queue<pair<pair<int, int>, int>> pendingVisits;

        pendingVisits.push({source, 0});

        grid[source.first][source.second] = 0;

        while(!pendingVisits.empty()){

            pair<pair<int, int>, int > curr = pendingVisits.front();

            pendingVisits.pop();

            int row = curr.first.first;

            int col = curr.first.second;

            int step = curr.second;

            

            //reached at the destination

            if(row == destination.first and col == destination.second){

                return step;

            }

            // down

            if(isSafe(row + 1, col, n, m) and grid[row + 1][col] == 1){

                pendingVisits.push({{row + 1, col}, step + 1});

                grid[row + 1][col] = 0;

            }

            

            // up

            if(isSafe(row - 1, col , n, m) and grid[row - 1][col] == 1){

                pendingVisits.push({{row - 1, col}, step + 1});

                grid[row - 1][col] = 0; 

            }

            

             // left

            if(isSafe(row, col - 1, n, m) and grid[row][col - 1] == 1){

                pendingVisits.push({{row, col - 1}, step + 1});

                grid[row][col - 1] = 0;

            }

            

            // right

            if(isSafe(row, col + 1 , n, m) and grid[row][col + 1] == 1){

                pendingVisits.push({{row, col + 1}, step + 1});

                grid[row][col + 1] = 0; 

            }

            

        }

        return  -1;  

    }

};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends