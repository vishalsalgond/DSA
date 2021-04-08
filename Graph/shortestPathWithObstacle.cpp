class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int n = grid.size(), m = grid[0].size();
        queue<vector<int>> Q;
        //Q({x, y, steps till now, remaining k})
        Q.push({0, 0, 0, k});
        
        vector<vector<int>> vis(n, vector<int>(m, -1));
        
        while(!Q.empty()) {
            
            auto front = Q.front();
            Q.pop();
            
            int x = front[0], y = front[1], steps = front[2], rem_k = front[3];
            
            //I am out of grid
            if(x < 0 || y < 0 || x >= n || y >= m)
                continue;
            
            //Got the answer!
            if(x == n - 1 && y == m - 1)
                return steps;
            
            //If I encounter a obstacle then remove it if remaining k > 0
            if(grid[x][y] == 1) {
                if(rem_k > 0) rem_k--;
                else continue;
            }
            
            //If I have already visited this cell throgh some other path
            //and in that path I had more k value than current path
            //then lets just continue on that path
            
            if(vis[x][y] != -1 && vis[x][y] >= rem_k)
                continue;
            
            vis[x][y] = rem_k;
            
            //add my neighbouring cells
            Q.push({x + 1, y, steps + 1, rem_k});
            Q.push({x - 1, y, steps + 1, rem_k});
            Q.push({x, y + 1, steps + 1, rem_k});
            Q.push({x, y - 1, steps + 1, rem_k});
        }
        
        
        return -1;
        
    }
};
