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
    int n, k, m;
    cin >> n >> k >> m;
    vi v(n);
    vector<ll> s(n + 1);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());

    for (int i = n - 1; i >= 0; i--)s[i] = s[i + 1] + v[i];

    double r = 0;
    for (int i = 0; i < n; i++) {
        if (m < i) break;
        ll rest = m - i, cnt = n - i;
        r = max(r, (s[i] + min(cnt * k, rest)) / double(cnt));
    }
    printf("%.9lf", r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
