#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back

int n, m;
int k[100005];
int a[100005][4];

int d[100005][2];

int sz = 1 << 18;
int tre[4][1 << 19];
int streak[100005][2];
int reach[100005][2];
map<int, int> idx[4];


void up(int *t, int i, int v) {
    int s = sz + i;
    while (s) {
        t[s] = min(t[s], v);
        s /= 2;
    }
}

int read(int *t, int i, bool is_min) {
    int s = sz, e = sz + sz - 1;
    int r = n + 1;

    if (is_min) e = sz + i - 1;
    else s = sz + i + 1;

    while (s <= e) {
        if (s % 2 == 1) r = min(r, t[s]), s++;
        if (e % 2 == 0) r = min(r, t[e]), e--;
        s /= 2;
        e /= 2;
    }
    return r;
}

int r[100005];

void trace(int y, int x) {
    for (int i = y + 1; i <= n; i++)r[i] = x;

    while (y > 0) {
        r[y] = x;
        int from = d[y][x];
        x ^= 1;
        for (y = y - 1; y > from; y--)
            r[y] = x;
    }
    for (int i = 1; i <= n; i++)cout << r[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(tre, 63, sizeof(tre));

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> k[i] >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];

    a[0][1] = a[0][3] = m;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            idx[j][k[i]] = 0;
            idx[j][a[i][j]] = 0;
        }
    }

    for (auto &i : idx) {
        int j = 0;
        for (auto it = i.begin(); it != i.end(); it++, j++)
            it->second = j;
    }

    for (int i = n; i >= 0; i--) {
        if (a[i][0] <= k[i] && k[i] <= a[i][1])
            streak[i][0] = max(streak[i + 1][0], i);

        up(tre[0], idx[0][a[i][0]], i);
        up(tre[1], idx[1][a[i][1]], i);
        reach[i][0] = min(
                read(tre[0], idx[0][k[i]], false) - 1,
                read(tre[1], idx[1][k[i]], true) - 1
        );

        if (a[i][2] <= k[i] && k[i] <= a[i][3])
            streak[i][1] = max(streak[i + 1][1], i);

        up(tre[2], idx[2][a[i][2]], i);
        up(tre[3], idx[3][a[i][3]], i);
        reach[i][1] = min(
                read(tre[2], idx[2][k[i]], false) - 1,
                read(tre[3], idx[3][k[i]], true) - 1
        );

        reach[i + 1][0] = min(reach[i][1], streak[i + 1][0]);
        reach[i + 1][1] = min(reach[i][0], streak[i + 1][1]);
    }
    reach[0][0] = min(reach[0][1], streak[0][0]);
    reach[0][1] = min(reach[0][0], streak[0][1]);

    int ll = 0, rr = 0;
    for (int i = 1; i <= n; i++) {
        d[i][0] = d[i][1] = -1;
        if (reach[rr][1] >= i - 1 && a[i][2] <= k[i - 1] && k[i - 1] <= a[i][3] && a[i][0] <= k[i] && k[i] <= a[i][1])
            d[i][0] = rr;

        if (reach[ll][0] >= i - 1 && a[i][0] <= k[i - 1] && k[i - 1] <= a[i][1] && a[i][2] <= k[i] && k[i] <= a[i][3])
            d[i][1] = ll;

        if (d[i][0] != -1 && reach[ll][0] < reach[i][0]) ll = i;
        if (d[i][1] != -1 && reach[rr][1] < reach[i][1]) rr = i;
    }

    if (reach[rr][1] >= n) {
        cout << "Yes" << endl;
        trace(rr, 1);
    } else if (reach[ll][0] >= n) {
        cout << "Yes" << endl;
        trace(ll, 0);
    } else
        cout << "No" << endl;
}
