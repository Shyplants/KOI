#include<bits/stdc++.h>

using namespace std;

const int MAX_M = 2e3 + 3;
const int MAX_N = 2e3 + 3;

int m, n, robot[MAX_M][MAX_N], dp[MAX_M][MAX_N];

int main()
{
	scanf("%d %d", &m, &n);

	for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j) {
		scanf("%1d", &robot[i][j]);
	}

	int ans = 0;
	for(int j=1; j<n; ++j) {
		for(int i=1; i<=m; ++i) {
			dp[i][j] = max(dp[i][j], dp[i-1][j-1] + robot[i][j]);
			dp[i][j] = max(dp[i][j], dp[i][j-1] + robot[i][j]);
			dp[i][j] = max(dp[i][j], dp[i+1][j-1] + robot[i][j]); 

			ans = max(ans, dp[i][j]);
		}
	}

	printf("%d\n", ans);
	return 0;
}