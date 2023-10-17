// Code only for Contest. Try my best <3
#include <bits/stdc++.h>
using namespace std;

// Defines
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define ln cout << '\n'
#define ms(d, i) memset(d, i, sizeof d)
#define all(x) (x).begin(), (x).end()
#define fastio {ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);}
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << '\n';
#define NguyenLuong ""

// Type definitions
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
#ifdef OStree
// Policy-based data structure
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K> using indexed_multiset = tree<K, null_type, less_equal<K>, rb_tree_tag, tree_order_statistics_node_update>;
#define fbo find_by_order
#define ook order_of_key
#endif
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) {a = min(a, b);}
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) {a = max(a, b);}

// Constants + Random
random_device dev;
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f; const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7; // 998244353;

void file() {
    fastio;
    if (fopen(NguyenLuong".inp", "r")) {
        freopen(NguyenLuong".inp", "r", stdin);
        freopen(NguyenLuong".out", "w", stdout);
    }
}

void solve() {
    int n; cin >> n;
    cout << (n == 2 || n % 2 ? "NO" : "YES");
}

int main() {
    file();
//    int t; cin >> t; while (t--)
    solve();
    return 0;
}

