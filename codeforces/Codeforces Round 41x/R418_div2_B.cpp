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

void f(vi a, vi &b, int x, int val) {
    a[x] = val;
    int c = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) c++;
    }
    if (c == 1) {
        for (int y: a)cout << y << " ";
        exit(0);
    }
}

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n), c(n + 1, -1);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;

    int aa, bb;
    for (int i = 0; i < n; i++) {
        if (c[a[i]] != -1) {
            aa = c[a[i]];
            bb = i;
        }
        c[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        if (c[i] == -1) {
            f(a, b, aa, i);
            f(a, b, bb, i);
        }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
