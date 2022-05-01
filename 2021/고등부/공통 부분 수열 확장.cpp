#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
const int MAX_LEN = 2e5 + 5;
const int ALPHA = 26;

char x[MAX_LEN], y[MAX_LEN], w[MAX_LEN];
int xSum[ALPHA][MAX_LEN];
int ySum[ALPHA][MAX_LEN];
pii xPos[MAX_LEN], yPos[MAX_LEN];

bool check(int xLeft, int xRight, int yLeft, int yRight) // [xLeft...xRight], [yLeft...yRight]
{
	if(xLeft > xRight || yLeft > yRight) return false;

	for(int i=0; i<ALPHA; ++i) {
		if((xSum[i][xRight] - xSum[i][xLeft-1]) && (ySum[i][yRight] - ySum[i][yLeft -1])) return true;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int T;
	cin >> T;

	while(T--) {
		cin >> (x + 1); // 1-base for prefix sum
		cin >> (y + 1);
		cin >> (w + 1);

		int xLen = strlen(x+1);
		int yLen = strlen(y+1);
		int wLen = strlen(w+1);

		int idx = 1;
		for(int i=1; i<=xLen; ++i) {
			for(int j=0; j<ALPHA; ++j) {
				xSum[j][i] = xSum[j][i-1] + (x[i]-'a' == j);
			}

			if(x[i] == w[idx] && idx <= wLen) {
				xPos[idx++].first = i;
			}
		}

		idx = wLen;
		for(int i=xLen; i>=1; --i) {
			if(x[i] == w[idx] && idx >= 1) {
				xPos[idx--].second = i;
			}
		}

		idx = 1;
		for(int i=1; i<=yLen; ++i) {
			for(int j=0; j<ALPHA; ++j) {
				ySum[j][i] = ySum[j][i-1] + (y[i]-'a' == j);
			}

			if(y[i] == w[idx] && idx<=wLen) {
				yPos[idx++].first = i;
			}
		}

		idx = wLen;
		for(int i=yLen; i>=1; --i) {
			if(y[i] == w[idx] && idx>=1) {
				yPos[idx--].second = i;
			}
		}

		bool ans = false;
		ans |= check(1, xPos[1].second-1, 1, yPos[1].second-1);
		for(int i=1; i<wLen && !ans; ++i)
			ans |= check(xPos[i].first+1, xPos[i+1].second-1, yPos[i].first+1, yPos[i+1].second-1);
		ans |= check(xPos[wLen].first+1, xLen, yPos[wLen].first+1, yLen);

		cout << ans << '\n';
	}

	return 0;
}