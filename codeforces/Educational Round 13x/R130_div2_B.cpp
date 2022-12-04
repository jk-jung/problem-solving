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
    int n, q;
    cin >> n >> q;
    vi v(n);
    vector<ll> s(n + 1);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++)s[i] = s[i - 1] + v[i - 1];
    while (q--) {
        int x, y;
        cin >> x >> y;
        int z = x - y;
        cout << s[n - z] - s[n - x] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
