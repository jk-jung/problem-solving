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
    int n, k, m;
    cin >> n >> k >> m;
    vi v(m);
    map<int, int> c;
    for (int &x: v)cin >> x, c[x]++;
    int r = 0;
    int last = 0;
    for (int i = 1; i <= n; i++) {
        if (last + k <= i || c.count(i)) {
            r++;
            last = i;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
