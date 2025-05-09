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
    int n, m;
    cin >> n >> m;
    vector<pi> v(n);
    for (auto &[x, y]: v)cin >> x >> y;
    sort(v.begin(), v.end());
    int r = 2;
    m *= 2;
    for (int i = 1; i < n; i++) {
        int s = v[i - 1].F * 2 + v[i - 1].S;
        int e = v[i].F * 2 - v[i].S;
        int dif = e - s;
        if (dif >= m)r++;
        if (dif > m) r++;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
