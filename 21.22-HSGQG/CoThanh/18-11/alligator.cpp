#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 2005 , MOD = 1e9 + 7 , inf = 1e9,
        row[4] = {0 , 1 , 0 , -1},
        col[4] = {-1 , 0 , 1 , 0};

void file() {
    freopen("alligator.inp" , "r" , stdin);
	freopen("alligator.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int m , n , a[N][N] , ans = 0 , f[N][N][5], cnt = 0 , vis[N][N];

bool check(int u , int v) {
	if(u < 1 || v < 1 || u > m || v > n) return false;
	return true;
}

int Dfs(int x , int y , int t) {
//	if(cnt == 16e6 ) exit(0);
	if(vis[x][y] == 2) return 0;
	if(f[x][y][t] != -1) return f[x][y][t];
//	++cnt;
	//cout << cnt << ' ' << x << ' ' << y << ' ' << t << ' ' << vis[x][y] << '\n';
//	if(cnt == 16e6) exit(0);
	if(!check(x, y)) return 1; 
	vis[x][y] = 2;
	int res = 1;
	int nxt = a[x + row[t]][y + col[t]];
	if(nxt != -1 && t != nxt && check(x + row[t] , y + col[t])) res &= Dfs(x + row[t], y + col[t], nxt);
	res &= Dfs(x + row[t], y + col[t] , t);
	vis[x][y] = 1;
	f[x][y][t] = res;
	return res;
}

int main() {
	file();
	cin >> m >> n;
	for(int i = 1 ; i <= m ; i++)
	for(int j = 1 ; j <= n ; j++) {
		char x;
		cin >> x;
		if(x == 'W') a[i][j] = 0;
		if(x == 'S') a[i][j] = 1;
		if(x == 'E') a[i][j] = 2;
		if(x == 'N') a[i][j] = 3;
		if(x == '.') a[i][j] = -1;
	}
	memset(f , -1 , sizeof(f));
	for(int i = 1 ; i <= m ; i++)
	for(int j = 1 ; j <= n ; j++)
	if(a[i][j] != -1) ans += Dfs(i , j , a[i][j]);
	
	cout << ans;
	
	return 0;
}



