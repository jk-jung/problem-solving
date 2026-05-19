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
    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    vi a(n), b(m);
    for (int &x: a)cin >> x, x += ta;
    for (int &x: b)cin >> x;

    int r = -1;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < m && b[j] < a[i])j++;
        int cnt = k - i;
        if (cnt < 0)break;
        if (cnt >= m - j) {
            cout << -1 << endl;
            return;
        }
        r = max(r, b[j + cnt] + tb);
    }
    if(n == k)r = -1;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
