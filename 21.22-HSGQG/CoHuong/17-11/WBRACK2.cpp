#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 250 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("WBRACK2.inp" , "r" , stdin);
	freopen("WBRACK2.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

map<ll , string> f[N][2];
ll n ;
string ans = "" , k;

string Plus(string a , string b) {
	if(a.size() > b.size()) swap(a , b);
	while(a.size() < b.size()) a = '0' + a;
	int nho = 0;
	string res = "";
	for(int i = a.size() - 1 ; i >= 0 ; i--) {
		int s = (a[i] - '0') + (b[i] - '0') + nho;
		nho = s / 10;
		res = char(s % 10 + '0') + res;
	}
	if(nho) res = '1' + res;
	return res;
}

string Minus(string a , string b) {
	while(b.size() < a.size()) b = '0' + b;
	int nho = 0;
	string res = "";
	for(int i = a.size() - 1 ; i >= 0 ; i--) {
		int s = (a[i] - '0') - (b[i] - '0') - nho;
		if(s < 0) s += 10 , nho = 1;
		else nho = 0;
		res = char(s + '0') + res;
	}
    while(res.size() > 1 && res[0] == '0') res.erase(0 , 1);
	return res;
}

bool Greater(string a , string b) {
	if(a.size() == b.size()) 	return a >= b;
	return a.size() >= b.size();
}

string calc(int id , int ok , int s) {
	if(f[id][ok].count(s)) return f[id][ok][s];
	if(id == 2 * n) {
		f[id][ok][s] = ((ok) ? "1" : "0");
		return f[id][ok][s];
	}
	string res = "0";
	int open = (id + s) / 2;
	int close = id - open;
	if(open < n) res = Plus(res , calc(id + 1 , ok | (s + 1 < 0) , s + 1));
	if(close < n) res = Plus(res ,calc(id + 1 , ok | (s - 1 < 0) , s - 1));
	f[id][ok][s] = res;
	return res;
}

void Get(int id , int ok , int s) {
	if(id == 2 * n) return;
	int open = (id + s) / 2;
	int close = id - open;
	if(open < n) {
		if(f[id + 1][ok | (s + 1 < 0)].count(s + 1)) {
			string res = f[id + 1][ok | (s + 1 < 0)][s + 1];
			if(Greater(res , k)) ans += '(' , Get(id + 1 , ok | (s + 1 < 0) , s + 1) , k = "0";
			else k = Minus(k , res);
		}
	}
	if(close < n && k != "0") {
		if(f[id + 1][ok | (s - 1 < 0)].count(s - 1)) {
			ans += ')';
			Get(id + 1 , ok | (s - 1 < 0) , s - 1);
			k = "0";
		}
	}
}

int main() {
	file();
	cin >> n >> k;
	calc(0 , 0 , 0);
	Get(0 , 0 , 0);
	cout << ans;
	return 0;
}

