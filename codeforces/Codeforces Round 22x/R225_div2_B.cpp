#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vi v(m);
    for (int i = 0; i < n; i++)for (int &x: v)cin >> x;
    cout << m * (m - 1) / 2 << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < m - i; j++) {
            int x = k == 0 ? j - 1 : j;
            int y = k == 0 ? j : j - 1;
            cout << x + 1 <<" " << y  + 1 << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
