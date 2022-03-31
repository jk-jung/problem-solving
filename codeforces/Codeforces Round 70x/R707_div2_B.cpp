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
    int n, h = 0;
    cin >> n;
    vector<pi> v;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        h++;
        if (h > 0) {
            v.pb({max(1, h - x + 1), 1});
            v.pb({h + 1, -1});
        }
    }
    sort(v.begin(), v.end());

    int st = 0;
    vi r;
    for (int i = 1, j = 0; i <= h; i++) {
        while (j < v.size() && v[j].F == i)st += v[j++].S;
        r.pb(st > 0 ? 1 : 0);
    }
    for (int x: r)cout << x << " ";
    cout << endl;
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
