#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, ret;
	cin >> n;

	for(int i=7; i>=0; --i) {
		if((n >> i) & 1) {
			ret = (1 << i);
			break;
		}
	}

	cout << ret << '\n';
	return 0;
}