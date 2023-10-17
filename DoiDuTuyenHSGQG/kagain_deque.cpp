#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7;
ll n , a[N] , st[N] , endd[N] , t , Max , st_id , en_id;
deque <ll> dq;
void file()
{
	//freopen(".inp","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void solve()
{
	cin >> n ;
	for (int i = 1; i <= n ; i++) cin >> a[i];
	dq.clear();
	Max = INT_MIN , st_id = INT_MAX ;
	for (int i = 1; i <= n ; i++)
	{
		while (dq.size() && a[dq.back()] >= a[i]) dq.pop_back();
		if(dq.size() == 0) st[i] = 0;
		else  st[i] = dq.back();
		dq.push_back(i);
	}
	dq.clear();
	for (int i = n; i >= 1 ; i--)
	{
		while (dq.size() && a[dq.back()] >= a[i]) dq.pop_back();
		if(dq.size() == 0) endd[i] = n + 1;
		else  endd[i] = dq.back();
		dq.push_back(i);
	}
	
	for (int i = 1 ; i <= n ; i++) 
	{
		//cout << st[i] << ' ' << endd[i] << endl;
		if (((endd[i] - st[i] - 1) * a[i]) == Max && st[i] + 1 < st_id) 
		{
			st_id = st[i] + 1;
			en_id = endd[i] - 1;
		}
		if (((endd[i] - st[i] - 1) * a[i]) > Max) 
		{
			Max = (endd[i] - st[i] - 1) * a[i] ;
			st_id = st[i] + 1;
			en_id = endd[i] - 1;
		}
		
    }
    cout << Max << ' ' << st_id << ' ' << en_id << '\n';
}
int main()
{
  file();
  cin >> t ;
  while (t --) solve();
  return 0;
}

