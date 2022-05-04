#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX_R = 450;
const int MAX_COLOR = 5e4 + 4;

int dp[MAX_R][MAX_COLOR];    // dp[i][j] = 가장 바깥원의 반지름이 i이고 파랑 페인트의 양을 j만큼 사용하여 나타낼 수 있는 경우의 수
                             //            가장 바깥원의 반지름i 그릴때 필요한 페인트(레드+블루) 총량 : i*(i+1)/2, 파랑 페인트의 양이 j일때 빨간 페인트의 양은 i*(i+1)/2 - j
int pSum[MAX_R][MAX_COLOR];  // pSum[i][j] = sum(dp[i][0] ... dp[i][j])

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int tc;
	cin >> tc;

	dp[0][0] = 1;

	for(int i=1; i < MAX_R; ++i) {        // i = 가장 바깥원의 반지름
		dp[i][0] = 1;
		pSum[i][0] = 1;

		for(int j=1; j<MAX_COLOR; ++j) {    // j = 사용한 파랑 페인트 양

			if(j <= i*(i+1)/2) {              // j -> [0 ... i*(i+1)/2]
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

		for(r=1; r < MAX_R; ++r) {     // r = 가장 바깥원의 반지름
			int a2 = r*(r+1)/2 - a, sum;

			a2 = max(a2, 0);             // a2 = 필요한 파랑 물약의 최소양
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