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

int a[505];
int b[505];
int d[505][505];

void solve() {
    int n, l, k;
    cin >> n >> l >> k;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)cin >> b[i];
    a[n] = l;

    memset(d, 64, sizeof(d));
    int none = d[0][0];
    int r = none;

    d[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int t = 0; t <= k; t++) {
            if (d[i][t] == none)continue;
            for (int j = i + 1; j <= n; j++) {
                int need = j - i - 1;
                if (need + t > k)break;
                d[j][t + need] = min(d[j][t + need], d[i][t] + (a[j] - a[i]) * b[i]);
            }
            if (i == n)r = min(r, d[i][t]);
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
