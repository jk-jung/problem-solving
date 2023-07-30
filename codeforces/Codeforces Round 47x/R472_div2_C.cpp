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
    int n, u;
    cin >> n >> u;
    vi v(n);
    for (int &x: v)cin >> x;
    double r = 0;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(v.begin(), v.end(), v[i] + u) - v.begin() - 1;
        if (j - i >= 2) {
            double t = (double) (v[j] - v[i + 1]) / (v[j] - v[i]);
            r = max(r, t);
        }
    }
    if (r == 0) cout << -1 << endl;
    else printf("%.10lf\n", r);;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
