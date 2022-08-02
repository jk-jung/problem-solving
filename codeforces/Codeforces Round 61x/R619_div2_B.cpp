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
    int n;
    cin >> n;
    vi v(n), x;
    for (int &y: v)cin >> y;

    int r = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] == -1 && v[i - 1] == -1) continue;
        else if (v[i] == -1) x.pb(v[i - 1]);
        else if (v[i - 1] == -1)x.pb(v[i]);
        else r = max(r, ab(v[i] - v[i - 1]));
    }
    sort(x.begin(), x.end());

    int m = 0;
    if(!x.empty()) {
        m = (x[0] + x.back()) / 2;
        r = max(r, max(m - x[0], x.back() - m));
    }
    cout << r << " " << m << endl;
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
