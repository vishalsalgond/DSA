/https://leetcode.com/problems/word-ladder/submissions/


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int level = 1, n = wordList.size();
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        queue <string> Q;
        Q.push(beginWord);
        Q.push("/"); //to mark end of one level
        dict.erase(beginWord);

        while(!Q.empty()) {
            string top  = Q.front();
            Q.pop();
    
            if(top == endWord)
                return level;
    
            if(top == "/") {
                level++;
                if(!Q.empty()) Q.push("/");
                continue;
            }
            
            //push all words that are neighbours of current word
            //i. e. having only one character different
            for(int i = 0; i < top.length(); i++) {
                char tmp = top[i];
                for(int j = 0; j < 26; j++) {
                    top[i] = 'a' + j;
                    if(dict.find(top) != dict.end()) {
                        Q.push(top);
                        if(!dict.empty()) dict.erase(top);
                        
                    }
                }
                top[i] = tmp;
            }
        }

        return 0;
    }
};
