ll power(ll a, ll x, ll mod) {
	if(x == 0)	return 1;
	if(x & 1) 	return power(a * a % mod, x >> 1, mod) * a % mod;
	else		return power(a * a % mod, x >> 1, mod); 
}