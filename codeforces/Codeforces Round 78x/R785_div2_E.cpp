#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <set>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

vi v;

ll mul(ll x, int y) {
    if (x == -1)return y;
    else if (y >= 20) return 0;
    x *= (1 << y);
    return x >= (1 << 20) ? 0 : x;
}

map<pi, int> tt;

int cnt2(int x) {
    int r = 0;
    while(x) {
        x /= 2;
        r += x;
    }
    return r;
}

int check(int n, int k) {
    k = max(0, k);
    pi key = pi(n, k);
    if(tt.count(key))return tt[key];

    int r = 0, nn = cnt2(n);
    for(int i=k;i<=n;i++){
        int c = nn - cnt2(i) - cnt2(n - i);
        c = c == 0 ? 1 : 0;
        r = (r + c) % 2;
    }
    return tt[key] = r;
}

void solve() {
    int n, k;
    cin >> n >> k;
    v.resize(n);
    for (int &x: v)cin >> x;
    vi r(1 << 20);

    for (int i = 0; i < n; i++) {
        ll val = -1;
        for (int j = i; j < n; j++) {
            val = mul(val, v[j]);
            if (val == 0)break;

            int used = 2;
            if (i == 0 && j == n - 1)used = 0;
            else if (i == 0 || j == n - 1)used = 1;

            int cnt = j - i + 1;
            int rest = n - cnt - used;
            if(used + rest >= k) {
                if(check(rest, k - used)) {
                    r[val] ^= 1;
                }
            }
        }
    }

    int flag = 0;
    for(int i=(1 << 20) - 1;i>=0;i--){
        flag |= r[i];
        if(flag)cout << r[i];
    }
    if(!flag)cout << 0;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
