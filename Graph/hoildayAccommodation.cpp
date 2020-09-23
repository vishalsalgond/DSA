https://www.spoj.com/problems/HOLI/


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
//LCM
inline ll lcm(ll a, ll b) { return ((a / gcd(a, b)) * b); }
//MODULO OPEARTIONS
inline ll add(ll a, ll b) { return ((( (a % mod) + (b % mod)) % mod) + mod ) % mod ; }
inline ll sub(ll a, ll b) { return ((( (a % mod) - (b % mod)) % mod) + mod ) % mod ; }
inline ll mul(ll a, ll b) { return ((( (a % mod) * (b % mod)) % mod) + mod ) % mod ; }
//POWER
ll fastpow(ll x, ll y) {
  ll res = 1; x = x % mod;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1 ;
    x = (x * x) % mod;
  }
  return (res % mod);
}
//MODULAR INVERSE (based on fermat's little theorem, works when m is prime)
ll inv(ll x, ll m) { return fastpow(x , m - 2);}
//MODULAR DIVISION (given numbers need not be co-prime)
ll moddiv(ll a, ll b) {
  ll temp = gcd(a, b);
  a /= temp;
  b /= temp;
  return ((a * inv(b, mod)) % mod);
}
//=========================  template ends here  ===========================

//if there are n-1 edges that means it is a tree
//find out maximum how many paths can go through every edge

int find_ver(vector <pii> graph[], int curr, vector<int> &vis, vector<int> &count, ll &ans, int V) {
  vis[curr] = 1;
  count[curr] = 1;

  //dfs of a tree
  for (auto nbr_pair : graph[curr]) {
    int nbr = nbr_pair.F, cost = nbr_pair.S;
    if (!vis[nbr]) {
      //when your nbr returns its count then
      //find total number of nodes that can travel
      //through the edge between you and your nbr
      count[curr] += find_ver(graph, nbr, vis, count, ans, V);
      ans += (ll)(2 * cost) * min(count[nbr], V - count[nbr]);
    }
  }

  return count[curr];
}

ll solve(vector <pii> graph[], int V) {

  vector <int> vis(V + 1, 0), count(V + 1, 0);

  ll ans = 0;
  find_ver(graph, 1, vis, count, ans, V);

  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input1.txt", "r", stdin);
  freopen("output1.txt", "w", stdout);
#endif
  int T; cin >> T;
  for (int i = 1; i <= T; i++) {
    int V;
    cin >> V ;
    vector <pii> graph[V + 1];

    for (int i = 0; i < V - 1; i++) {
      int u , v, c;
      cin >> u >> v >> c;
      graph[u].push_back({v, c});
      graph[v].push_back({u, c});
    }
    cout << "Case #" << i << ":" << " ";
    cout << solve(graph, V) << nl;
  }

  return 0;
}

