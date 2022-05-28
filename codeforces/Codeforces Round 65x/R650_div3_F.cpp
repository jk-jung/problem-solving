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

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt, prev, pos, s, e, cnt2;
    vi v(n), d(n);
    for (int &x: v)cin >> x, cnt[x]++;
    for (int i = 0; i < n; i++) {
        if (!s.count(v[i]))s[v[i]] = i;
        e[v[i]] = i;
    }

    int last = -1;
    for (auto [k, _]: cnt) {
        prev[k] = last;
        last = k;
    }

    int r = 0;
    for (int i = 0; i < n; i++) {
        int x = v[i];

        d[i] = 1;
        if (cnt[x] >= 2 && pos.count(x))
            d[i] = d[pos[x]] + 1;

        int y = prev[x];
        if (y != -1) {
            d[i] = max(d[i], cnt2[y] + 1);
            if(e[y] < i) {
                d[i] = max(d[i], d[s[y]] + cnt[y]);
            }
        }

        r = max(r, d[i]);
        pos[x] = i;
        cnt2[x]++;
    }

    cout << n - r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
