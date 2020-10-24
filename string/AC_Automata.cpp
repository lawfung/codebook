struct AC_Automata {
	static const int N = 1e4 + 10;
	static const int SGM = 26;
	int ch[N][SGM], val[N], sz;
	int fail[N];
	int que[N], qs, qe;
	void init() {
		memset(ch[0], 0, sizeof ch[0]);
		val[0] = 0;
		sz = 1;
		qs = qe = 0;
	}
	inline int idx(char c) {return c - 'A';}
	void insert(string s, int v){
		int now = 0;
		for(char c : s){
			int i = idx(c);
			if(!ch[now][i]) {
				memset(ch[sz], 0, sizeof (ch[sz]));
				val[sz] = 0;
				ch[now][i] = sz++;
			}
			now = ch[now][i];
		}
		val[now] += v;
		return;
	}
	void build() {
		que[qe++] = 0;
		while(qs != qe) {
			int t = que[qs++];
			for(int i = 0; i < SGM; ++ i) {
				int now = ch[t][i];
				if(!now)	continue;
				que[qe++] = now;
				int v = fail[t];
				while(v && !ch[v][i]) v = fail[v];
				fail[now] = t ? ch[v][i] : 0;
				val[now] += val[fail[now]];
			}
		}
		for(qs = 1; qs < qe; ++ qs) {
			int now = que[qs];
			for(int i = 0; i < SGM; ++ i) {
				if(ch[now][i] == 0)
					ch[now][i] = ch[fail[now]][i];
			}
		}
	}
} ac;
// ac.init()
// ac.insert(s, x) * n
// ac.build()