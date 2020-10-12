//https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1


// The task is to complete this function

// M[][]: input matrix
// n: size of matrix (n*n)
int getId(int M[MAX][MAX], int n)
{
    stack <int> S;
    
    for(int i = 0; i < n; i++) {
        S.push(i);
    }
    
    while(!S.empty()) {
        int first = S.top();
        S.pop();
        
        if(!S.empty()) {
            int second = S.top();
            S.pop();
            
            if(M[first][second] == 1) 
                S.push(second);
            
            else 
                S.push(first);
            
        } else {
            S.push(first);
            break;
        }
    }

    
    for(int i = 0; i < n; i++) {
        if(i != S.top() && M[i][S.top()] == 0)
            return -1;
    }
    
    for(int i = 0; i < n; i++) {
        if(i != S.top() && M[S.top()][i] == 1) {
            return -1;
        }
    }
    
    return S.top();
}
