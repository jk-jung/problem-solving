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
    int n, l;
    cin >> n >> l;
    vi v(n);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    double ans = max(v[0], l - v[n - 1]);
    for (int i = 0; i < v.size() - 1; i++) {
        ans = max(ans, (v[i + 1] - v[i]) / 2.0);
    }
    printf("%.10f\n", ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
