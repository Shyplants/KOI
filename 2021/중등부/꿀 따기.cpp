#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 5;
int n, ans;
int honey[MAX_N], pSum[MAX_N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> honey[i];
		pSum[i] = pSum[i-1] + honey[i];
	}

	for(int i=2; i<n; ++i) {
		ans = max(ans, 2*pSum[n] - honey[1] - honey[i] - pSum[i]);
		ans = max(ans, pSum[n-1] - honey[i] + pSum[i-1]);
		ans = max(ans, pSum[i] - honey[1] + pSum[n-1] - pSum[i-1]);
	}

	cout << ans << '\n';
	return 0;
}