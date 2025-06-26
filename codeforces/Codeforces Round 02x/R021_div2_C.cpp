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
    int n;
    cin >> n;
    vi v(n), t(n);
    int s = 0;
    for (int &x: v)cin >> x, s += x;
    if (s % 3) {
        cout << 0;
        return;
    }

    s /= 3;
    for (int i = 0, ss = 0; i < n - 1; i++) {
        ss += v[i];
        if (ss == s * 2)t[i]++;
    }
    for (int i = n - 2; i >= 0; i--)t[i] += t[i + 1];
    ll r = 0;
    for (int i = 0, ss = 0; i < n - 2; i++) {
        ss += v[i];
        if (ss == s)r += t[i + 1];
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
