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
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;

    ll r = 0;
    for (int x: a) {
        int i = lower_bound(b.begin(), b.end(), x) - b.begin();
        ll tmp = 1ll << 60;
        for (int k = -1; k < 1; k++) {
            int j = i + k;
            if (0 <= j && j < m) tmp = min(tmp, ab((ll) x - b[j]));
        }
        r = max(r, tmp);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
