#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_N = 2e5 + 5;

int n, k;
ll pSum[4];

struct Data{
	char alpha;
	ll num, numerator, denominator;

	bool operator< (Data& rhs) const {
		return numerator * rhs.denominator > denominator * rhs.numerator;
	}

	void calc() {
		denominator = pSum[alpha - 'A'];
		pSum[alpha - 'A'] += num;
		numerator = num;
	}

	void print() {
		cout << alpha << ' ' << num << '\n';
	}
} _data[MAX_N];

bool cmp(const Data& a, const Data& b) {
	return a.num > b.num;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> n >> k;

	for(int i=0; i<4; ++i) cin >> pSum[i];

	for(int i=0; i<n; ++i) {
		cin >> _data[i].alpha >> _data[i].num;
	}

	sort(_data, _data+n, cmp);
	for(int i=0; i<n; ++i) _data[i].calc();

	sort(_data, _data+n);
	for(int i=0; i<k; ++i) _data[i].print();
	return 0;
}