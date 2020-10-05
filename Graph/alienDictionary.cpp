//https://practice.geeksforgeeks.org/problems/alien-dictionary/1


// User function Template for C++

/*
dict : array of strings denoting the words in alien langauge
N : Size of the dictionary
K : Number of characters
*/

void topo(map<char,vector<char>> &adj, map <char,bool> &vis, stack <char> &stk, char curr) {
    
    vis[curr] = true;
    
    for(char next : adj[curr]) {
        if(!vis[next]) {
            topo(adj, vis, stk, next);
        }
    }
    
    stk.push(curr);
}

string findOrder(string dict[], int N, int K) {
    
    map<char, vector<char>> adj;
    string ans;
    
    if(N == 1) {
        ans += dict[0][0];
        return ans;
    }
    
    //Build the graph
    for(int i = 0; i < N - 1; i++) {
        string word1 = dict[i], word2 = dict[i + 1];
        int n1 = word1.length(), n2 = word2.length();
        
        int ptr1 = 0, ptr2 = 0;
        while(ptr1 < n1 && ptr2 < n2 && word1[ptr1] == word2[ptr2]) {
            ptr1++;
            ptr2++;
        }
        
        if(ptr1 < n1 && ptr2 < n2) 
            adj[word1[ptr1]].push_back(word2[ptr2]);
        
    }
    
    map <char, bool> vis;
    stack <char> stk;
    
    //Do topological sorting
    for(auto node : adj)
        if(!vis[node.first])
            topo(adj, vis, stk, node.first);
    
    while(!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }
    
    
    if(ans.length() > K) return ans.substr(0, 12);
    return ans;
}
