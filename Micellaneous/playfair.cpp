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

vector<vector<char>> matrix(5, vector<char> (5, 'X'));
unordered_map<char, pair<int,int>> mp;

string encryption(string message) {
    int i = 0;
    string encryptedText = "";
    // if(message.length() & 1) message += 'z';

    while(i < message.length()) {
        int r1 = mp[message[i]].first, c1 = mp[message[i]].second;
        int r2, c2;

        if(i + 1 == message.length()) {
        	message += 'z';
        }

        if(message[i + 1] == message[i]) {
            r2 = mp['x'].first; c2 = mp['x'].second;
            i++;
        } else {
            r2 = mp[message[i + 1]].first; c2 = mp[message[i + 1]].second;
            i += 2;
        }
            
        if(r1 == r2) {
            encryptedText += matrix[r1][(c1 + 1)%5];
            encryptedText += matrix[r1][(c2 + 1)%5];
        }
        else if (c1 == c2) {
            encryptedText += matrix[(r1 + 1)%5][c1];
            encryptedText += matrix[(r2 + 1)%5][c1];
        }
        else {
            encryptedText += matrix[r1][c2];
            encryptedText += matrix[r2][c1];
        }
    }

    return encryptedText;
}

string decryprion(string message) {
	int i = 0;
    string decryptedText = "";
    if(message.length() & 1) message += 'z';

    while(i < message.length()) {
        int r1 = mp[message[i]].first, c1 = mp[message[i]].second;
        int r2 = mp[message[i + 1]].first, c2 = mp[message[i + 1]].second;
            
        if(r1 == r2) {
            decryptedText += matrix[r1][(c1 - 1 + 5)%5];
            decryptedText += matrix[r1][(c2 - 1 + 5)%5];
        }
        else if (c1 == c2) {
            decryptedText += matrix[(r1 - 1 + 5)%5][c1];
            decryptedText += matrix[(r2 - 1 + 5)%5][c1];
        }
        else {
            decryptedText += matrix[r1][c2];
            decryptedText += matrix[r2][c1];
        }
        i += 2;
    }

    return decryptedText;
}

bool check_in_key(string key, char n) {
    for(char x : key) {
        if(x == n) return true;
    }

    return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input1.txt", "r", stdin);
  freopen("output1.txt", "w", stdout);
#endif
    string key;
    cin >> key;

    for(char &x : key) if(x == 'j') x = 'i';

    int key_ptr = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(key_ptr < key.length())
                matrix[i][j] = key[key_ptr];
                mp[key[key_ptr]] = {i, j};
                key_ptr += 1;
        }
    }

    char ptr = 'a';
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(matrix[i][j] == 'X') {
                // cout << ptr << " ";
                while(ptr == 'j' || mp.find(ptr) != mp.end()) ptr++;
                // cout << ptr << endl;
                matrix[i][j] = ptr;
                mp[ptr] = {i, j};
            }
        }
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    string message;
    cin >> message;

    string encryptedText = encryption(message);
    string decryptedText = decryprion(encryptedText);

    cout << encryptedText << endl;
    cout << decryptedText << endl;
  return 0;
}

