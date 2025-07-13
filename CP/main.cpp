#include <bits/stdc++.h>
using namespace std;

// Fast I/O
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// Shortcuts
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

// Types
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

// Debug macro (disable for online judges)
#ifdef LOCAL
    #define debug(x) cerr << #x << " = " << x << endl;
#else
    #define debug(x)
#endif

// Constants
const int MOD = 1e9+7;
const int INF = 1e9;
const ll LINF = 1e18;

// Directions (for grids)
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// Custom functions
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// Main
int main() {
    fast_io;

    int t = 1;
    cin >> t;
    while(t--) {
        // Solve each test case here
    }

    return 0;
}
