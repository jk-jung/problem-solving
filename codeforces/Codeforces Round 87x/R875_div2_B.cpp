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

map<int, int> read(int n) {
    map<int, int> r;
    for (int i = 0, x, y = -1, c = 0; i < n; i++) {
        cin >> x;
        if (x == y) c++;
        else c = 1;
        r[x] = max(r[x], c);
        y = x;
    }
    return r;
}

int f(map<int, int> &a, map<int, int> &b) {
    int r = 0;
    for (auto [x, y]: a) r = max(r, y + b[x]);
    return r;
}

void solve() {
    int n;
    cin >> n;
    map<int, int> a = read(n), b = read(n);
    cout << max(f(a, b), f(b, a)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
