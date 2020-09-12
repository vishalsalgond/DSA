#include<bits/stdc++.h>
using namespace std;
#define lp0(i,n) for(i=0;i<n;i++)
#define lp1(i,n) for(i=1;i<=n;i++)
#define lpr(i,n) for(i=n-1;i>=0;i--)
#define ll long long
#define nl "\n"
#define gcd __gcd
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;
typedef vector<int>   vi;
typedef vector<ll>    vl;
typedef vector<pii>   vpii;
typedef vector<pl>    vpl;
typedef vector<vi>    vvi;
typedef vector<vl>    vvl;
const ll mod = 1e9 + 7;

//=========================  template ends here  ===========================

const int n = 4;
int done = (1<<n) - 1;
int dist[4][4] = {
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};
int dp[(1<<n)][n];

int tsp(int mask, int pos) {

    //1111..1 will be base case
    if(mask == done) {
        return dist[pos][0];
    }
    //return if already calculated
    if(dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    //goto all unvisited cities
    for(int city = 0; city < n; city++) {
        if((mask&(1<<city)) == 0) {
            int tempAns = dist[pos][city] + tsp(mask|(1<<city), city);
            ans = min(ans, tempAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for(int i = 0; i < (1<<n); i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    cout << tsp(1,0) << endl;
    return 0;
}

