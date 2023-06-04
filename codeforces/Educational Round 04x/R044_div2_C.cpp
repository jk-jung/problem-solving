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
    int n, k, l;
    cin >> n >> k >> l;
    vi v(n * k);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    if (v[0] + l < v[n - 1]) {
        cout << 0;
        return;
    }

    int m = 0;
    while (m < v.size() && v[m] <= v[0] + l)m++;
    ll r = 0;
    for (int i = 0, pos = 0; i < n; i++) {
        int rest = m - pos - (n - i);
        int need = min(k - 1, rest);
        r += v[pos];
        pos += need + 1;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
