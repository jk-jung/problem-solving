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


void dfs(int s, int e, int dep, vi &v, vi &r) {
    int m = -1, idx;
    for (int i = s; i <= e; i++) {
        if (m < v[i]) {
            m = v[i];
            idx = i;
        }
    }
    if (m == -1)return;

    r[idx] = dep;
    dfs(s, idx - 1, dep + 1, v, r);
    dfs(idx + 1, e, dep + 1, v, r);
}

void solve() {
    int n;
    cin >> n;
    vi v(n), r(n);
    for (int &x: v)cin >> x, x--;

    dfs(0, n - 1, 0, v, r);

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
