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

vi v[300005];
int ii[300005];
int used[300005];

void solve() {
    int n, m;
    cin >> n >> m;
    int r = 0, pos = 0;
    vi t;
    for (int idx = 0; idx < m; idx++) {
        int x, y;
        cin >> x >> y;
        if (x == 1) {
            v[y].pb(idx);
            t.pb(idx);
            r++;
        } else if (x == 2) {
            for (; ii[y] < v[y].size(); ii[y]++) {
                int k = v[y][ii[y]];
                if (used[k] == 0) {
                    used[k] = 1;
                    r--;
                }
            }
        } else {
            for (; pos < y; pos++) {
                int k = t[pos];
                if (used[k] == 0) {
                    used[k] = 1;
                    r--;
                }
            }
        }
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
