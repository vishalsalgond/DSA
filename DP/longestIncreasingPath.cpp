//https://leetcode.com/problems/longest-increasing-path-in-a-matrix/


#define F first
#define S second
class Solution {
public:
    int n, m;

    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &memo, vector<vector<int>> &vis, pair<int,int> curr) 
    {
        int x = curr.F, y = curr.S;
        
        if(vis[x][y]) return 0;
        
        if(memo[x][y] != -1)  return memo[x][y];

        vis[x][y] = 1;
        
        int up = 1, down = 1, left = 1, right = 1;
        if(x + 1 < n && matrix[x + 1][y] > matrix[x][y]) right = 1 + dfs(matrix, memo, vis, {x + 1, y});
        if(x - 1 >= 0 && matrix[x - 1][y] > matrix[x][y]) left = 1 + dfs(matrix, memo, vis, {x - 1, y});
        if(y + 1 < m && matrix[x][y + 1] > matrix[x][y]) up = 1 + dfs(matrix, memo, vis, {x, y + 1});
        if(y - 1 >= 0 && matrix[x][y - 1] > matrix[x][y]) down = 1 + dfs(matrix, memo, vis, {x, y - 1});
        
        vis[x][y] = 0;
        
        return memo[x][y] = max(max(left, right), max(up, down));

    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

       n = matrix.size();
       if (n == 0) return 0;
        m = matrix[0].size();
       vector<vector<int>> memo(n, vector<int>(m, -1));
       vector<vector<int>> vis(n, vector<int>(m, 0));

       int ans = 0;
       for(int i = 0; i < n; i++) {
           for(int j = 0; j < m; j++) {
               ans = max(ans, dfs(matrix, memo, vis, {i , j}));
           }
       }

       return ans;
    }
};
