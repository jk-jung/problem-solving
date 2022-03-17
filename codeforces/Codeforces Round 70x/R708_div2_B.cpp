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
    int n, m;
    cin >> n >> m;
    vi v(m);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        v[x % m]++;
    }
    int r = v[0] > 0;
    for (int s = 1, e = m - 1; s <= e; s++, e--) {
        if (v[s] == 0 && v[e] == 0)continue;
        if (s == e) r ++;
        else {
            int t = min(v[s], v[e]) + 1;
            r += 1 + max(0, v[s] - t) + max(0, v[e] - t);
        }
    }
    cout << r << endl;
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
