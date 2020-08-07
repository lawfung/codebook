#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int int_fast64_t
// build_phi, power, eb
// M has primitive root when M = 2, 4, p^n, 2p^n
#define eb emplace_back
ll power(ll a, ll x, ll mod) {
	if(x == 0)	return 1;
	if(x & 1) 	return power(a * a % mod, x >> 1, mod) * a % mod;
	else		return power(a * a % mod, x >> 1, mod); 
}
void build_phi(int ax[], int n){
	for(int i = 1; i <= n; ++i)
		ax[i] = i;
	for(int i = 1; i <= n; ++i)
		for(int j = i + i; j <= n; j += i)
			ax[j] -= ax[i];
}
int phi[50000];
ll Primitive_root(ll n) {
	if(n == 2)	return 1;
	vector<ll> sol;
	ll val = phi[n];
	for(ll i = 2; i * i <= val ; ++ i){
		if(val % i == 0){
			sol.eb(i);
			while(val % i == 0) val /= i;
		}
	}
	if(val != 1) sol.eb(val);
	for(ll i = 2; i < n; ++ i){
		if(__gcd(i, n) != 1)	continue;
		ll ok = 1;
		for(auto to : sol){
			if(power(i , phi[n] / to , n) == 1){
				ok = 0;
				break;
			}
		}
		if(ok)
			return i;
	}
	return -1;
}
int main() {
	build_phi(phi, 44444);
	cout << Primitive_root(32004) << '\n';
}