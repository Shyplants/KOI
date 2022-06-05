#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Data
{
    vector<ll> l, r;
    ll ret, zCnt;
};

ll ans;
ll l, r;
int k, bCnt;
Data pre[64], bit[64];

int num_trailing_zeros(ll num) {
    int cnt = 0;
    while(num > 0 && num % 2 ==0) num /= 2, cnt++;
    return cnt;
}

int num_leading_zeros(ll num) {
    int cnt = 0;
    while(num > 0 && (num & (1LL << 63)) == 0) num <<= 1, cnt++;
    return cnt;
}

Data merge(Data sl, Data sr)
{
    Data cur;
    cur.l = sl.l;
    cur.r = sr.r;
    cur.ret = max(sl.ret, sr.ret);
    cur.zCnt = sl.zCnt + sr.zCnt;

    if(sl.zCnt <= k) {
        cur.l.pop_back();
        for(int i=0; i<(int)sr.l.size() && (int)cur.l.size() <= k; i++) {
            cur.l.push_back(sl.ret + sr.l[i]);
        }
    }

    if(sr.zCnt <= k) {
        cur.r.pop_back();
        for(int i=0; i<(int)sl.r.size() && (int)cur.r.size() <= k; i++) {
            cur.r.push_back(sr.ret + sl.r[i]);
        }
    }

    int k2 = min((ll)k, cur.zCnt);
    for(int i=k2-(int)sr.l.size()+1; i<(int)sl.r.size(); ++i) {
        cur.ret = max(cur.ret, sl.r[i] + sr.l[k2-i]);
    }

    return cur;
}

Data solve(ll s, ll e)
{
    ll m = s + (e-s)/2;
    int mCnt =num_trailing_zeros(m);

    if(l <= s && e <= r) return pre[mCnt];

    if(r < m) return solve(s, m-1);
    if(l > m) return solve(m+1, e);
    if(l == m) {
      Data sr = solve(m+1, e);
      return merge(bit[mCnt], sr);
    }
    Data sl = solve(s, m-1);
    if(r == m) return merge(sl, bit[mCnt]);
    Data sr = solve(m+1, e);
    return merge(merge(sl, bit[mCnt]), sr);
}

void precal()
{
    pre[0] = bit[0];
    int i=0;
    while(++i <= bCnt) {
        pre[i] = merge(merge(pre[i-1], bit[i]), pre[i-1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    ll n;
    int q, iter = 0;

    cin >> n >> q;

    bCnt = 63 - num_leading_zeros(n);
    bool subtask1 = (n == 1LL << bCnt);
    
    while(q--) {
        ans = 0;
        cin >> l >> r >> k;

        if(subtask1) {
            ans = min(r-l+1, (ll)k*2 + (l%2 || r%2));

            if(l%2 == 0 && r%2 == 0) {
                if((r-l)/2 > k) ans = k*2+1;
            }
        
            cout << ans << '\n';
            continue;
        }

        for(int i=0; i<=bCnt; ++i) {
            int cur = (n >> (bCnt-i)) & 1;
            bit[i].ret = k ? 1 : cur;
            bit[i].zCnt = 1 - cur;

            bit[i].l = vector<ll>(1, cur);
            bit[i].r = vector<ll>(1, cur);

            if(k && !cur) {
                bit[i].l.push_back(1);
                bit[i].r.push_back(1);
            }
        }
        precal();

        ans = (l == r ? bit[num_trailing_zeros(l)].ret : solve(1LL, (1LL << (bCnt+1)) - 1).ret);
        cout << ans << '\n'; 
    }

    return 0;
}