#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_N = 2e5 + 5;
const ll INF = 1ll*MAX_N*1e9;

int n, val[MAX_N];
vector<int> adj[MAX_N];
ll dp[MAX_N][2], g[MAX_N], ans;

void solve(int cur)
{
	dp[cur][0] = val[cur];
	dp[cur][1] = -INF;

	ll c1 = -INF;
	ll c2 = -INF;

	for(auto nxt : adj[cur]) {
		solve(nxt);

		if(dp[nxt][0] <= 0) {
			dp[cur][1] = max(dp[cur][1], g[nxt]);
		}
		else {
			dp[cur][0] += dp[nxt][0];
			dp[cur][1] = max(dp[cur][1], dp[nxt][1]);
		}

		if(c1 == -INF) c1 = g[nxt];
		else if(c2 == -INF) { 
			c2 = g[nxt];
			if(c2 > c1) swap(c2, c1);
		}
		else {
			if(g[nxt] > c1) {
				c2 = c1;
				c1 = g[nxt];
			}
			else if(g[nxt] > c2) c2 = g[nxt];
		}
	}

	g[cur] = max(dp[cur][0], c1);

	ans = max(ans, dp[cur][0] + dp[cur][1]);
	ans = max(ans, c1 + c2);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int par;

	cin >> n;
	cin >> val[1] >> par;

	for(int i=2; i<=n; ++i) {
		cin >> val[i] >> par;

		adj[par].push_back(i);
	}

	ans = -INF;
	solve(1);
	cout << ans << '\n';
	return 0;
}

/*
6
3 -1
2 1
4 1
5 1
2 4
7 4
*/