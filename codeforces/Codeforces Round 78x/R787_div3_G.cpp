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

int base = 255, n, m, inf = 1 << 30;
int d[255][255][555];
int v[255];

int go(int i, int last, int st) {
    if (ab(base - st) > m) return inf;
    if (i == n) return st == base ? 0 : inf;

    int &r = d[i][last][st];
    if (r != -1)return r;
    r = inf;

    for (int t = 0; t <= last; t++) {
        int val = ab(st - base);
        int need = ab(t - v[i]);
        if (t < v[i]) {
            r = min(r, go(i + 1, t, st + need) + val);
        } else {
            r = min(r, go(i + 1, t, st - need) + val);
        }
    }
    return r;
}

void solve() {
    memset(d, -1, sizeof(d));
    cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> v[i];

    cout << go(0, m, base) << endl;
}

// 4 1 0 0 0 1
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
