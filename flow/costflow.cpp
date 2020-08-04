const ll N = 5e2 + 5;
struct MCFlow{
	struct edge{
		int t, r;
		ll cap, cos;
		edge(int _t, int _r, ll _cp, ll _co) : t(_t), r(_r), cap(_cp), cos(_co){}
	};
	int n, S, T;
	vector<edge> adj[N];
	MCFlow(int _n,int _s,int _t) : n(_n), S(_s), T(_t) {
		for(int i = 0; i < n; ++ i)
			adj[i].clear();
	}
	void add(int s, int t, ll cap, ll cos){
		adj[s].eb(t, SZ(adj[t])  , cap, cos);
		adj[t].eb(s, SZ(adj[s])-1, 0  , -cos);
	}
	pll flow(){
		ll tc = 0, tf = 0, dis[N];
		int inq[N], pre[N], prE[N];
		while(1){
			memset(dis, INF, n * 8);
			memset(inq, 0  , n * 4);
			queue<int> qu;
			qu.push(S);
			inq[S] = 1;
			dis[S] = 0;
			while(SZ(qu)){
				int now = qu.front();
				qu.pop();
				inq[now] = 0;
				for(int i = 0; i < SZ(adj[now]); ++i){
					auto e = adj[now][i];
					if(e.cap && dis[now] + e.cos < dis[e.t]){
						dis[e.t] = dis[now] + e.cos;
						pre[e.t] = now;
						prE[e.t] = i;
						if(!inq[e.t]){
							qu.push(e.t);
							inq[e.t] = 1;
						}
					}
				}
			}
			if(dis[T] == INF)	break;
			ll mi = INF;
			for(int now = T; now != S; now = pre[now])
				mi = min(mi, adj[pre[now]][prE[now]].cap);
			for(int now = T; now != S; now = pre[now]){
				adj[pre[now]][prE[now] ]            .cap-=mi;
				adj[now][adj[pre[now]][prE[now]].r ].cap+=mi;
			}
			tc += mi * dis[T];
			tf += mi;
		}
		return pll(tf, tc);
	}
};