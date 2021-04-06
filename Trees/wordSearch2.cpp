//https://leetcode.com/problems/word-search-ii/

class Solution {
public:
    struct TrieNode {
        TrieNode *child[26];
        string word = "";
    };
    
    void dfs(int x, int y, TrieNode *ptr, vector<vector<char>>& board, vector<string> &ans) {
        
        char curr = board[x][y];
        int n = board.size(), m = board[0].size();
        
        if(curr =='$' || ptr -> child[curr - 'a'] == NULL)
            return;
        
        ptr = ptr -> child[curr - 'a']; //move to current character
        
        if(ptr -> word != "") {
            ans.push_back(ptr -> word);
            ptr -> word = ""; //to avoid duplicates
        }
        
        board[x][y] = '$'; //to avoid reusing the same alphabet twice
        
        if(x + 1 < n) dfs(x + 1, y, ptr, board, ans);
        if(x - 1 >= 0) dfs(x - 1, y, ptr, board, ans);
        if(y + 1 < m) dfs(x, y + 1, ptr, board, ans);
        if(y - 1 >= 0) dfs(x, y - 1, ptr, board, ans);
        
        board[x][y] = curr; //restore the character
    }
    
    TrieNode *buildTrie(vector<string>& words) {
        
        TrieNode *root = new TrieNode(); //create root node
        
        for(int i = 0; i < words.size(); i++) {
            TrieNode *ptr = root;
            for(char c : words[i]) {
                if(ptr -> child[c - 'a'] == NULL)
                    ptr -> child[c - 'a'] = new TrieNode();
                ptr = ptr -> child[c - 'a'];
            }
            ptr -> word = words[i]; //so that we can append the word in O(1)
        }
        
        return root;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        vector<string> ans;
        TrieNode *root = buildTrie(words);
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                dfs(i, j, root, board, ans); //start dfs from every cell in board
            }
        }
        
        return ans;
    }
};
