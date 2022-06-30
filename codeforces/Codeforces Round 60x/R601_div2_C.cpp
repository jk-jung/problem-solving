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

int v[100005][3];
int c[100005];
int cnt[4];
map<pi, vi> ck;

void solve() {
    int n;
    cin >> n;
    vi r(n);
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> v[i][j];
            c[v[i][j]]++;
        }
        sort(v[i], v[i] + 3);

        ck[{v[i][0], v[i][1]}].pb(v[i][2]);
        ck[{v[i][0], v[i][2]}].pb(v[i][1]);
        ck[{v[i][1], v[i][2]}].pb(v[i][0]);
    }
    for (int i = 0; i < n; i++) {
        cnt[1] = cnt[2] = cnt[3] = 0;
        for (int x: v[i])cnt[c[x]] = x;
        if (cnt[1] && cnt[2]) {
            r[0] = cnt[1];
            r[1] = cnt[2];
            r[2] = cnt[3];
            break;
        }
    }
    for (int i = 3; i < n; i++) {
        int x = r[i - 3];
        int y = min(r[i - 2], r[i - 1]);
        int z = max(r[i - 2], r[i - 1]);

        for (int k: ck[{y, z}])if (k != x)r[i] = k;
    }
    for (int x: r)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
