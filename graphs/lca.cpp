const int Max = 1e5+3, Log = 20+1;
vector<int> adj[Max];
int memo[Max][Log];
int depth[Max];

void dfs(int node, int prev, int Depth) {
	depth[node] = Depth;
	memo[node][0] = prev;
	for(int i = 1; i < Log; ++i) {
		memo[node][i] = memo[memo[node][i-1]][i-1];
	}
	for(int to : adj[node]) {
		if(to == prev) continue;
		dfs(to, node, Depth+1);
	}
}

int LCA(int x, int y) {
	if(depth[x] < depth[y]) swap(x,y);
	int diff = depth[x] - depth[y];
	for(int k = Log-1; k >= 0; --k) {
		if(diff&(1<<k)) {
			x = memo[x][k];
		}
	}
	for(int k = Log-1; k >= 0; --k) {
		if(memo[x][k] != memo[y][k]) {
			x = memo[x][k];
			y = memo[y][k];
		}
	}
	if(x != y) x = memo[x][0];
	return x;
}
//dfs(1,1,0);
