pll p[MAX];
int n , idx[MAX] , pos[MAX];
long long wnt;
vector<pll> v;
// pll + , pll -, pll ^, eb, ALL
inline long long calcArea(pll x , pll y , pll z){
	long long val = abs(cross(y - x , z - x));
	return val;
}
inline int cmp1(pll x , pll y){
	return ((p[x.S] - p[x.F]) ^ (p[y.S] - p[y.F])) > 0;
}
int32_t main(){
	cin >> n >> wnt , wnt += wnt;
	for(int i = 0; i < n; ++ i)	cin >> p[i].X >> p[i].Y;
	sort(p, p + n);
	for(int i = 0; i < n; ++ i) idx[i] = i, pos[i] = i;
	for(int i = 0; i < n; ++ i)
		for(int j = 0; j < n; ++ j)
			v.eb(i, j);
	sort(ALL(v) , cmp1);
	// p : won't change : [A, B, C ...]
	// sorted : [C, B, A]
	// (idx to) pos : pos[A] = 2, pos[B] = 1, pos[C] = 0
	// (pos to origin) idx : idx[0] = C, idx[1] = B, idx[0] = A
	for(auto line : v){
		int fr = pos[line.F] , ba = pos[line.S] , now;
		if(fr > ba) swap(fr , ba);
		now = fr;
		RREP(i , lgN , 0){
			int to = now - (1 << i);
			if(to >= 0 && calcArea(p[idx[fr]] , p[idx[ba]] , p[idx[to]]) <= wnt) now = to;
		}
		now = ba;
		RREP(i , lgN , 0){
			int to = now + (1 << i);
			if(to < n && calcArea(p[idx[fr]] , p[idx[ba]] , p[idx[to]]) <= wnt) now = to;
		}
		swap(idx[fr] , idx[ba]) , swap(pos[line.F] , pos[line.S]);
	}
	cout << "No" << endl;
	return 0;
}
