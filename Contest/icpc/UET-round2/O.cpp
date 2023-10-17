#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 2e5 + 5;

int n, m;
ll f[N], g[N];
vector<ll> pre[N], suf[N];
vector<int> adj[N];
void file()
{
    //freopen(".inp" , "r" , stdin);
    //freopen(".out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void dfs1(int u, int pu)
{
    f[u] = 1;

    for (int i = 0; i <= adj[u].size() + 2; i ++) pre[u].pb(1) ,  suf[u].pb(1);
    

    for (int i = 1; i <= adj[u].size(); i ++)
    {
        int v = adj[u][i-1];
        pre[u][i] = pre[u][i-1];
        if ( v == pu ) continue;
        dfs1(v, u);
        f[u] = f[u] * ( 1 + f[v] ) % m;
        pre[u][i] = pre[u][i] * (1 + f[v]) % m;
    }

    for (int i = adj[u].size(); i >= 1; i --)
    {
        int v = adj[u][i-1];
        suf[u][i] = suf[u][i+1];
        if ( v == pu ) continue;
        suf[u][i] = suf[u][i] * (1 + f[v]) % m;
    }
}

void dfs2(int u, int pu)
{
    for (int i = 1; i <= adj[u].size(); i ++)
    {
        int v = adj[u][i-1];
        if ( v == pu ) continue;
        g[v] = ( ( pre[u][i-1] * suf[u][i+1] ) % m * g[u] % m + 1 ) % m;
        dfs2(v, u);
    }
}

int main()
{
   
file();
    cin >> n;
    for (int i = 2; i <= n; ++i) {
    	int p; cin >> p;
    	adj[p].push_back(i);
    	adj[i].push_back(p);
	}
    m = 1e9 + 7;
    dfs1(1, 0);
    g[1] = 1;
    dfs2(1, 0);

    for (int i = 1; i <= n; i ++) cout << ( f[i] * g[i] ) % m << ' ';

    return 0;
}
