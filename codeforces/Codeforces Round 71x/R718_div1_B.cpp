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
    vector<vi> v;
    vector<vi> r(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            v.pb({x, i, j});
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++) {
        r[v[i][1]][i] = v[i][0];
    }
    for (int i = m; i < v.size(); i++) {
        int y = v[i][1];
        int vv = v[i][0];
        for (int k = 0; k < m; k++) {
            if(r[y][k] == 0) {
                r[y][k] = vv;
                break;
            }
        }
    }
    for (auto &t: r) {
        for (int x: t)cout << x << " ";
        cout << endl;
    }
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
