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

vi a(4), b(4), c(4);


bool ck(int y, int x, vi &v) {
    return v[0] <= x && x <= v[2] && v[1] <= y && y <= v[3];
}

bool can(int y, int x) {
    return !ck(y, x, b) && !ck(y, x, c);
}

void solve() {
    for (int &x: a)cin >> x, x *= 2;
    for (int &x: b)cin >> x, x *= 2;
    for (int &x: c)cin >> x, x *= 2;

    bool ok = 0;
    for (int i = a[0]; i <= a[2]; i++) {
        ok |= can(a[1], i);
        ok |= can(a[3], i);
    }
    for (int i = a[1]; i <= a[3]; i++) {
        ok |= can(i, a[0]);
        ok |= can(i, a[2]);
    }
    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
