ll a, c;
ll nxt(ll x, ll n) {
    return addd( mull( a, mull(x, x, n), n ), c, n);
}
ll solve(ll n) {
    if (isPrime(n)) return n;
    if (!(n & 1)) return 2;
    a = myRnd() % n; if (!a) a=1;
    c = myRnd() % n;
    while (c == 0 || c == 2) c = myRnd()%n;
    ll start = myRnd()%n;
    ll s1 = nxt(start, n), s2 = nxt(s1, n);
    while (true) {
        if (s1 == s2) {
            start = myRnd() % n;
            //a=myRnd()+1;
            a = Rnd() % n; if (!a) a = 1;
            c = Rnd() % n; while (c == 0 || c == 2) c = myRnd() % n;
            s1 = nxt(start, n), s2 = nxt(s1, n);
            continue;
        }
        ll g = gcd(abs(s1 - s2), n);
        if (g != 1) {
            return min(solve(g), solve(n / g));
        }
        s1 = nxt(s1, n); s2 = nxt(nxt(s2, n), n);
    }
}
