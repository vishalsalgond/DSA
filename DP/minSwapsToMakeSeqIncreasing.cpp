class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        
        int N = A.size();
        vector<int> swap(N, 1), no_swap(N, 0);
        
        for(int i = 1; i < N; i++) {
            
            swap[i] = no_swap[i] = INT_MAX;
            
            //elements are already in strictly increasing order
            if(A[i] > A[i - 1] && B[i] > B[i - 1]) {
                //swap at i - 1 and swap at i
                swap[i] = swap[i - 1] + 1;
                //do not swap at i - 1 and do not swap at i
                no_swap[i] = no_swap[i - 1];
            }
            
            if(B[i] > A[i - 1] && A[i] > B[i - 1]) {
                //do not swap at i - 1 an dswap a t i
                swap[i] = min(swap[i], no_swap[i - 1] + 1);
                //do not swap at i and swap at i - 1
                no_swap[i] = min(no_swap[i], swap[i - 1]);
            }
        }
        
        return min(swap[N - 1], no_swap[N - 1]);
        
    }
};
