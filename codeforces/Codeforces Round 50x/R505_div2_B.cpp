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

vi r;

void fac(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            r.pb(i);
            if (i != x / i)r.pb(x / i);
        }
    }
    if (x > 1)r.pb(x);
}

void solve() {
    int n;
    cin >> n;
    vector<pi> v(n);
    for (auto &[x, y]: v)cin >> x >> y;

    fac(v[0].F);
    fac(v[0].S);
    sort(r.begin(), r.end());
    r.erase(unique(r.begin(), r.end()), r.end());
    for (int k: r) {
        for (auto [a, b]: v) {
            if (a % k && b % k)goto NO;
        }
        cout << k;
        return;
        NO:;
    }
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
