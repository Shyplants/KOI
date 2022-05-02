#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_N = 1e5 + 5;

int n, avg;
int a[MAX_N], pSum[MAX_N];
ll dp[4];

ll solve()
{
	if(pSum[n] % 4 != 0) return 0;

	dp[0] = 1;
	avg = pSum[n] / 4;

	if(avg == 0) {
		ll cnt = 0;
		for(int i=1; i<n; ++i) {
			cnt += (pSum[i] == 0);
		}

		return cnt*(cnt-1)*(cnt-2)/6;
	}

	for(int i=1; i<n; ++i) {
		if(pSum[i] % avg == 0) {
			int cur = pSum[i] / avg;
			if(cur > 3) continue;

			dp[cur] += dp[cur-1];
		}
	}

	return dp[3];
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		pSum[i] = pSum[i-1] + a[i];
	}

	cout << solve() << '\n';
	return 0;
}