//https://leetcode.com/problems/permutation-sequence/


class Solution {
public:

    string ans;
    int fact[10];
    
    void factorial() {
        fact[0] = 1;
        for(int i = 1; i < 10; i++) {
            fact[i] = i * fact[i - 1];
        }
    }

    void stringPermute(string &s, int &k, int &permuation_no, int n) {

        if(n == 1) {
            ans = s;
            return;
        }

        int start = s.length() - n;
        for(int i = start; i < s.length(); i++) {
            if(k <= permuation_no + fact[n - 1]) {
                
                char x = s[i];
                s.erase(s.begin() + i);
                s.insert(s.begin() + start, x);

                stringPermute(s, k, permuation_no, n - 1);
                return;

            } else {
                permuation_no += fact[n - 1];
            }
        }
    }
    
    string getPermutation(int n, int k) {
        
        string s;
        for(int i = 1; i <= n; i++) {
            s += to_string(i);
        }

        factorial();
        int permuation_no = 0;
        stringPermute(s, k, permuation_no, n);
        
        return ans;
        
    }
};
