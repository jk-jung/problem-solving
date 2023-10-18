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
    vi v(n), r(n, 1 << 30);
    for (int &x: v)cin >> x;
    int x = 1 << 30;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0)x = i;
        r[i] = min(r[i], ab(x - i));
    }
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == 0)x = i;
        r[i] = min(r[i], ab(x - i));
    }
    for (int x: r)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
