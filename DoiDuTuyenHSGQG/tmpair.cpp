#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	ll n , dem = 1;
  cin >> n;
  for (int i = 2 ; i <= sqrt(n) ; i++) 
  {
  	
  	if (n % i == 0) 
	  {
	  	if (i * i == n) dem++;
	  	else dem += 2; 
	  }
  }
  dem = dem * 2;
  if (n % 2 == 0) dem--;
  cout << dem;
}

