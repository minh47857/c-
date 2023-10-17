#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 3e5 + 5 , MOD = 1e9 + 9;

using namespace std;

void file() {
	freopen("tourguide.inp" , "r" , stdin);
	freopen("tourguide.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , cnt[28][N] , dp[N] , sum , bit[28][2 * N];
string str;

int add(int a , int b) {
	a += b;
	if(a >= MOD) a -= MOD;
	if(a < 0) a += MOD;
	return a;
}

void update(int c , int pos , int val) {
	for(int i = pos ; i <= 2 * n + 1 ; i += (i & (-i))) 
		bit[c][i] = add(bit[c][i] , val);
}

int get(int c , int pos) {
	int res = 0;
	for(int i = pos ; i >= 1 ; i -= (i & (-i)))
		res = add(res , bit[c][i]);
	return res;
}

int main() {
	file();
	cin >> str;
	n = str.size() + 1;
	str = " *" + str;
	for(int c = 1 ; c <= 26 ; c++) 
	  for(int i = 1 ; i <= n ; i++) 
	  	cnt[c][i] = cnt[c][i - 1] + (str[i] == (c + 'a' - 1));
	dp[1] = 1;
	sum = 1;
	for(int c = 1 ; c <= 26 ; c++)
		update(c , n + 2 * cnt[c][1] , dp[1]);
	for(int i = 2 ; i <= n ; i++) {
		for(int c = 1 ; c <= 26 ; c++) 
			dp[i] = add(dp[i] , get(c , n + 2 * cnt[c][i] - i));
		dp[i] = add(sum , -dp[i]);
		sum = add(dp[i] , sum);
		for(int c = 1 ; c <= 26 ; c++)
			update(c , n + 2 * cnt[c][i] - i + 1 , dp[i]);	
	}
	cout << dp[n];
	return 0;
}


