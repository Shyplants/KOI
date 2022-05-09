#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAX_N = 1e5 + 5;

bool flag;
int n, m;
int A[MAX_N];
ll B[MAX_N], C[MAX_N];
vector<ll> xFix;
vector<pii> adj[MAX_N];   // {cost, target}


void solve(int cur, int a, ll b) {
	if(A[cur]) {
		if(A[cur] == a) {
			if(B[cur] != b) flag = true;
		}
		else {
			if((B[cur] - b) % 2) {
				flag = true;
				return;
			}

			xFix.push_back(a > 0 ? (B[cur] - b) / 2 : (b - B[cur]) / 2);
		}

		return;
	}

	A[cur] = a;
	B[cur] = b;
	C[cur] = -a*b;

	for(auto& nxt : adj[cur]) {
		solve(nxt.second, -a, nxt.first - b);
	}

}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		int u, v, w;

		cin >> u >> v >> w;
		adj[u].push_back({w, v});
		adj[v].push_back({w, u});
	}

	solve(1, 1, 0);

	sort(xFix.begin(), xFix.end());
	xFix.erase(unique(xFix.begin(), xFix.end()), xFix.end());

	if(flag || xFix.size() > 1) {
		cout << "No" <<'\n';
	}
	else {
		sort(C+1, C+n+1);
		ll x = (xFix.empty() ? C[(n+1)/2] : xFix[0]);
		
		cout << "Yes" << '\n';
		for(int i=1; i<=n; ++i) {
			cout << A[i]*x + B[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}