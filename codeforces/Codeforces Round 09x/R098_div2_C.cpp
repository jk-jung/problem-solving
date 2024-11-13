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
    vector<pi> v(n);
    for (auto &[x, y]: v)cin >> x >> y;
    int m = -1;

    sort(v.begin(), v.end());
    int r = 0;
    for (int i = 0; i < n;) {
        int x = v[i].F;
        while (i < n && v[i].F == x) {
            if (m > v[i].S)r++;
            m = max(m, v[i++].S);
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
