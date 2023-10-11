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

int n, m;
vector<string> v;
int d[2][2][55];

int f(int x, int y, int k) {
    int &r = d[x][y][k];
    if (r != -1) return r;
    if (k == n - 1) {
        if (x == 0) {
            for (int i = m - 1; i >= 0; i--)if (v[k][i] == '1')return r = i;
        } else {
            for (int i = 0; i < m; i++)if (v[k][i] == '1')return r = m - i - 1;
        }
    }
    if (x != y) return r = m;
    r = 1;
    if (x == 0) {
        for (int i = 0; i < m; i++)
            if (v[k][i] == '1') r = i * 2 + 1;
    } else {
        for (int i = 0; i < m; i++)
            if (v[k][i] == '1') {
                r = (m - i - 1) * 2 + 1;
                break;
            }
    }
    return r;
}

void solve() {
    memset(d, -1, sizeof(d));
    cin >> n >> m;
    v.resize(n);
    for (int i = n - 1; i >= 0; i--)cin >> v[i];
    m += 2;

    while(!v.empty() && v.back() == string(m, '0'))v.pop_back();
    n = v.size();
    int r = 1 << 30;
    for (int i = 0; i < (1 << n); i++) {
        int last = 0;
        int t = 0;
        for (int k = 0; k < n; k++) {
            int cur = i >> k & 1;

            t += f(last, cur, k);

            last = cur;
        }
        r = min(r, t);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
