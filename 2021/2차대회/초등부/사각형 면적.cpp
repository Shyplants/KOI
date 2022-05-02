#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, c;
	cin >> n >> c;

	int a = n, b = n;
	int x, y;

	for(int i=0; i<c; ++i) {
		cin >> x >> y;

		if(x >= a || y >= b) continue;

		if(b*x >= a*y) a = x;
		else b = y;
	}

	cout << a*b << '\n';
	return 0;
}