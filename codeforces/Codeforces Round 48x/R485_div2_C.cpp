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
    vi a(n), b(n), c(n, 1 << 30);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++)if (a[i] < a[j]) c[i] = min(c[i], b[i] + b[j]);
    }
    int r = 1 << 30;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j])r = min(r, b[i] + c[j]);
        }
    }
    if (r == (1 << 30))r = -1;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

        solve();
}
