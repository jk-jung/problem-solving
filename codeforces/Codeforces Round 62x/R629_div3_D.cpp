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
    vi v(n), r(n);
    for (int &x: v)cin >> x;

    r[0] = 1;
    for (int i = 1; i < n; i++) {
        if (v[i - 1] == v[i]) r[i] = r[i - 1];
        else r[i] = 3 - r[i - 1];
    }

    if (v[0] != v.back() && r[0] == r.back()) {
        for (int i = 1, flag = 1; i < n; i++) {
            if (flag) {
                if (v[i - 1] == v[i]) {
                    r[i] = 3 - r[i - 1];
                    flag = 0;
                }
            } else {
                if (v[i - 1] == v[i]) r[i] = r[i - 1];
                else r[i] = 3 - r[i - 1];
            }
        }
        if (r[0] == r.back())r.back() = 3;
    }

    int m = 1;
    for (int x: r)m = max(m, x);
    cout << m << endl;
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
