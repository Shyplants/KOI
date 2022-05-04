#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX_R = 450;
const int MAX_COLOR = 5e4 + 4;

int dp[MAX_R][MAX_COLOR];
int pSum[MAX_R][MAX_COLOR];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int tc;
	cin >> tc;

	dp[0][0] = 1;

	for(int i=1; i < MAX_R; ++i) {
		dp[i][0] = 1;
		pSum[i][0] = 1;

		for(int j=1; j<MAX_COLOR; ++j) {

			if(j <= i*(i+1)/2) {
				dp[i][j] = dp[i-1][j];
				if(j >= i) dp[i][j] += dp[i-1][j-i];

				dp[i][j] %= MOD;
			}
			pSum[i][j] = (pSum[i][j-1] + dp[i][j]) % MOD;
		}
	}
	
	while(tc--) {
		int a, b, r, ans = 0;
		cin >> a >> b;

		for(r=1; r < MAX_R; ++r) {
			int a2 = r*(r+1)/2 - a, sum;

			a2 = max(a2, 0);
			if(a2 > b) break;

			sum = (pSum[r][b] - pSum[r][a2] + MOD) % MOD;
			sum = (sum + dp[r][a2]) % MOD;
			
			ans += sum;
			ans %= MOD;
		}

		cout << ans << '\n';
	}
	return 0;
}