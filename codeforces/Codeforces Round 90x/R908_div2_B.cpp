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
    int n;
    cin >> n;
    vi v(n);
    vi t[1005];

    for (int &x: v)cin >> x;
    for (int i = 0; i < n; i++)t[v[i]].pb(i);

    vi r(n, 1);
    int c = 0;
    for (int i = 1; i <= 100; i++) {
        if (t[i].size() >= 2) {
            if (c == 0)r[t[i][0]] = 1, r[t[i][1]] = 2;
            else r[t[i][0]] = 1, r[t[i][1]] = 3;
            c++;
        }
    }
    if (c < 2)cout << -1 << endl;
    else {
        for (int x: r)cout << x << " ";
        cout << endl;
    }
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
