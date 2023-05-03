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
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;

    bool ok = true;
    for (char x: a)if (x == '*') ok = false;
    if (n - 1 > m || (ok && a != b)) {
        cout << "NO\n";
        return;
    }

    int s = 0;
    for (int i = 0; i < n; i++, s++) {
        if (a[i] == '*') break;
        if (i >= m || a[i] != b[s]) {
            cout << "NO\n";
            return;
        }
    }
    int e = m - 1;
    for (int i = n - 1; i >= 0; i--, e--) {
        if (a[i] == '*') break;
        if (e < 0 || a[i] != b[e]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
