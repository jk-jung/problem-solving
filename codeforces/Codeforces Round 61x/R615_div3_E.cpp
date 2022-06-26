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

int n, m;

int calc(vi &a, map<int, int> &ck) {
    map<int, int> shift;
    for (int i = 0; i < n; i++) {
        if (ck.count(a[i])) {
            int y = ck[a[i]], z = i;
            if (z < y)z += n;
            shift[z - y]++;
        }
    }
    int r = n;
    for (auto [x, y]: shift)
        r = min(r, n - y + x);
    return r;
}

void solve() {
    cin >> n >> m;
    vector<vi> v(m, vi(n));
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> v[j][i];

    int r = 0;
    for (int k = 0; k < m; k++) {
        map<int, int> ck;
        for (int i = 0, x = k + 1; i < n; i++, x += m)ck[x] = i;
        r += calc(v[k], ck);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
