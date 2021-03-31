//https://leetcode.com/problems/kth-ancestor-of-a-tree-node/


class TreeAncestor {
public:
    int height;
    vector<vector<int>> up;
    vector<int> depth;
    
    TreeAncestor(int n, vector<int>& parent) {
        height = ceil(log2(n));
        up = vector<vector<int>>(n, vector<int>(height));
        depth = vector<int>(n);
        
        depth[0] = 0;
        parent[0] = 0;
        
        // up[vertex][p] --> 2^p th parent of vertex
        
        for(int vertex = 0; vertex < n; vertex++) {
            up[vertex][0] = parent[vertex];
            
            if(vertex) 
                depth[vertex] = depth[parent[vertex]] + 1;
            
            for(int p = 1; p < height; p++) {
                //give me 2*p - 1 th parent of my 2^p - 1 th parent
                //eventually my 2^p th parent
                up[vertex][p] = up[up[vertex][p - 1]][p - 1];
            }
        }
        
    }
    
    int getKthAncestor(int node, int k) {
        
        //Binary lifting
        
        if(depth[node] < k) return -1;  //kth parent does not exist
        
        for(int i = 0; i < height; i++) {
            if(k & (1 << i)) {
                node = up[node][i];
            }
        }
        
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
