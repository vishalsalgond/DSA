//https://www.interviewbit.com/problems/subarray-with-given-xor/


int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<int> prefix(n);

    prefix[0] = A[0];
    unordered_map<int,int> mp;
    
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] ^ A[i];
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x = prefix[i] ^ B;
        
        ans += mp[x];
        
        if(x == 0) ans++;
        
        mp[prefix[i]]++;
    
    }
    
    return ans;
}
