#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int T;
	cin >> T;

	while(T--) {
		int n, m, k, d;

		cin >> n >> m >> k >> d;

		int sum1 = k*n*m*(m-1)/2;
		int sum2 = n*(n-1)/2*m*m;
		int B = d / (sum1 + sum2);
		int ans = (sum1 + sum2 > d ? -1 : B*(sum1 + sum2)) ;

		cout << ans << '\n';
	}
	return 0;
}