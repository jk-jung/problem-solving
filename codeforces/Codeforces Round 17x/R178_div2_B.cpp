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
    vi a, b;
    for (auto &[x, y]: v) {
        cin >> x >> y;
        if (x == 1)a.pb(y);
        else b.pb(y);
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int r = 1 << 30;
    for (int i = 0; i <= a.size(); i++) {
        int w = 0;
        for (int k = i; k < a.size(); k++)w += a[k];
        for (int j = 0; j <= b.size(); j++) {
            int w2 = w;
            for (int k = j; k < b.size(); k++)w2 += b[k];
            int t = i + j * 2;
            if (t >= w2) {
                r = min(r, t);
            }
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
