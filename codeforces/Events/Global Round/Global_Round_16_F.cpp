#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

int n, m;
ll a[200005];
ll d[200005][2];
ll min_pos[200005];
pi seg[200005];
pi tar[200005];

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 0; i < m; i++)cin >> seg[i].F >> seg[i].S;
    sort(seg, seg + m);
    sort(a + 1, a + n + 1);
    a[0] = -(1ll << 50);
    a[n + 1] = (1ll << 50);

    int pos = 0;
    for (int i = 1; i <= n + 1; i++) {
        int M = 0;
        while (pos < m && seg[pos].F <= a[i]) {
            if (seg[pos].S < a[i]) {
                if (M > 0 && tar[M - 1].F == seg[pos].F);
                else tar[M++] = seg[pos];
            }
            pos++;
        }

        min_pos[M] = a[i];
        for (int j = M - 1; j >= 0; j--)
            min_pos[j] = min(min_pos[j + 1], tar[j].S);
        d[i][0] = d[i - 1][0] + (a[i] - min_pos[0]);
        d[i][1] = d[i - 1][0] + (a[i] - min_pos[0]) * 2;

        for (int j = 0; j < M; j++) {
            ll a_dist = tar[j].F - a[i - 1];
            ll b_dist = a[i] - min_pos[j + 1];
            d[i][0] = min(d[i][0], d[i - 1][1] + a_dist + b_dist);
            d[i][0] = min(d[i][0], d[i - 1][0] + a_dist + a_dist + b_dist);
            d[i][1] = min(d[i][1], d[i - 1][1] + a_dist + b_dist + b_dist);
            d[i][1] = min(d[i][1], d[i - 1][0] + a_dist + a_dist + b_dist + b_dist);
        }
    }
    assert(pos == m);
    cout << d[n + 1][0] << '\n';
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
