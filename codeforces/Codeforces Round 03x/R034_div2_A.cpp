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
    vi v(n);
    for (int &x: v)cin >> x;
    int r = 1 << 30, idx = 0;
    for (int i = 0; i < n; i++) {
        int j = i + 1 == n ? 0 : i + 1;
        if (ab(v[i] - v[j]) < r) {
            r = ab(v[i] - v[j]);
            idx = i;
        }
    }
    cout << idx + 1 << " " << (idx + 1 == n ? 1 : idx + 2) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
