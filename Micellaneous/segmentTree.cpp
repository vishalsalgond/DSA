#include<bits/stdc++.h>
using namespace std;
#define lp(i,s,n) for(i=s;i<=n;i++)
#define ll long long
#define gcd __gcd
#define endl "\n"
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
template <typename T>
inline void readA(vector<T>& arr, int n) {
	arr.resize(n);
	for (auto& element : arr) cin >> element;
}
template <typename T>
inline void printA(const vector<T> &arr) {
	for (T ele : arr) cout << ele << " ";
	cout << endl;
}
template <typename T>
inline T lcm(T a, T b) { return ((a / gcd(a, b)) * b); }
template <typename T>
inline T add(T a, T b)
{ return ((( (a % mod) + (b % mod)) % mod) + mod ) % mod; }
template <typename T>
inline T sub(T a, T b)
{ return ((( (a % mod) - (b % mod)) % mod) + mod ) % mod; }
template <typename T>
inline T mul(T a, T b)
{ return ((( (a % mod) * (b % mod)) % mod) + mod ) % mod; }
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
ll inv(ll a, ll m) { return fastpow(a , m - 2);}
//MODULAR DIVISION (given numbers need not be co-prime)
ll moddiv(ll a, ll b) {
	ll temp = gcd(a, b);
	a /= temp;
	b /= temp;
	return ((a * inv(b, mod)) % mod);
}
///////////////////////// CODE STARTS HERE  /////////////////////////////


vector<int> tree;

int solve(int node, int node_low, int node_high, const int &q_low, const int &q_high) {

	if (q_high < node_low || q_low > node_high)
		return 0;

	if (q_low <= node_low && q_high >= node_high)
		return tree[node];

	int mid = (node_low + node_high) / 2;

	return solve(2 * node, node_low, mid, q_low, q_high) +
	       solve(2 * node + 1, mid + 1, node_high, q_low, q_high);

}

void segmentTree() {

	int N, Q;
	cin >> N >> Q;
	vector<int> a(N);

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	int size = 1;
	while (size < N) size *= 2;

	tree.resize(2 * size, 0);

	for (int i = 0; i < N; i++) {
		tree[i + size] = a[i];
	}

	for (int i = size - 1; i >= 1; i--) {
		// + for range sum queries
		tree[i] = tree[2 * i] + tree[2 * i + 1];
	}

	while (Q--) {
		int low, high; cin >> low >> high;
		// use for 1-based indexing
		low--; high--;
		cout << solve(1, 0, size - 1, low, high) << endl;
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	int T = 1;
	for (int i = 1; i <= T; i++) {
		segmentTree();
	}
	return 0;
}

