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
//Read array
template <typename T>
inline void readA(vector<T>& arr, int n) {
	arr.resize(n);
	for (auto& element : arr) cin >> element;
}
//Print array
template <typename T>
inline void printA(const vector<T> &arr) {
	for(T ele : arr) cout << ele << " ";
	cout << nl;
}

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

void foo() {
  
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
	foo();
  }
  return 0;
}

