#include <cstring>
#include <cstdio>
#include <cmath>
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
    vi v(n);
    for (int i = 0, x; i < m; i++) {
        cin >> x;
        v[x - 1]++;
    }
    int s = 0, e = m, r = -1;
    while (s <= e) {
        int k = (s + e) / 2;

        ll st = 0;
        for (int x: v) {
            if (x <= k)st += (k - x) / 2;
            else st -= (x - k);
        }

        if (st >= 0)e = k - 1, r = k;
        else s = k + 1;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
