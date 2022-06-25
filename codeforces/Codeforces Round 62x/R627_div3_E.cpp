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

int n, h, s, e;
int d[2005][2005];

int is_good(int x) {
    return s <= x && x <= e ? 1 : 0;
}

void solve() {
    cin >> n >> h >> s >> e;
    vi v(n);
    for (int &x: v)cin >> x;
    memset(d, -1, sizeof(d));

    d[0][v[0]] = is_good(v[0]);
    d[0][v[0] - 1] = is_good(v[0] - 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < h; j++) {
            if (d[i - 1][j] != -1) {
                for (int k = -1; k <= 0; k++) {
                    int t = (j + v[i] + k) % h;
                    d[i][t] = max(d[i][t], d[i - 1][j] + is_good(t));
                }
            }
        }
    }

    int r = 0;
    for (int i = 0; i < n; i++)for (int j = 0; j < h; j++)r = max(r, d[i][j]);
    cout << r << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
