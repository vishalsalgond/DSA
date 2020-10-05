//https://leetcode.com/problems/shortest-path-in-binary-matrix/submissions/


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return -1;

        //If starting point or ending point are blocked
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        
        vector <vector<int>> vis(n, vector<int>(n, 0));

        queue <pair<int,int>> Q;
        Q.push({0, 0});
        Q.push({-1, -1});  //Will act as a marker for end of level
        vis[0][0] = 1;

        int directions[8][2] = {{0, 1},{0,-1},{1,0},{-1,0},{1,-1},{-1,-1},{1,1},{-1,1}};

        int level = 1;
        while(!Q.empty()) {
            auto curr = Q.front();
            Q.pop();

            int x = curr.first, y = curr.second;

            if(x == n - 1 && y == n - 1) 
                return level;

            if(x == -1 && y == -1) {
                level++;
                //If there are still some more levels
                if(!Q.empty()) {
                    Q.push({-1, -1});
                }
                continue;
            }
            

            //Check all 8 directions
            for(int i = 0; i < 8; i++) {
                int next_x = x + directions[i][0], next_y = y + directions[i][1];
                
                if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < n) {
                   if(!vis[next_x][next_y] && grid[next_x][next_y] == 0) {
                       vis[next_x][next_y] = 1;
                        Q.push({next_x, next_y});
                    } 
                }
            }
        }

        return -1;
    }
};
