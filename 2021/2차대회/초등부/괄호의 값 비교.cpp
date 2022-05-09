#include<bits/stdc++.h>

using namespace std;

const int MAX_LEN = 3e6 + 6;

typedef struct MyData{
	char str[MAX_LEN];
	int pCnt[MAX_LEN];
	int len, cnt;

	void init() {
		memset(pCnt, 0, sizeof(pCnt));
		
		cin >> str;
		len = strlen(str);
		cnt = 0;
	}

	void calc() {
		for(int i=0; i<len; ++i) {
			if(str[i] == '(') cnt++;
			else {
				cnt--;
				if(str[i-1] == '(') {
					pCnt[cnt]++;
				} 
			}
		}

		for(int i=0; i<len; ++i) {
			pCnt[i+1] += pCnt[i] / 2;
			pCnt[i] %= 2;
		}
	}
} MyData;

MyData a, b;

void solve() {
	for(int i=MAX_LEN-1; i>=0; i--) {
		if(!a.pCnt[i] && b.pCnt[i]) {
			cout << '<' << '\n';
			return;
		}

		if(a.pCnt[i] && !b.pCnt[i]) {
			cout << '>'  << '\n';
			return;
		}
	}

	cout << '=' << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	int TC;

	cin >> TC;
	while(TC--) {
		a.init();
		b.init();

		a.calc();
		b.calc();

		solve();
	}
	return 0;
}