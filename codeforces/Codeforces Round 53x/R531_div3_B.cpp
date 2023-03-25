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
    int n, k;
    cin >> n >> k;
    vector<pi> v(n);
    vi r(n);
    map<int, int> ck;
    bool tt = false;
    for (int i = 0; i < n; i++) {
        cin >> v[i].F, v[i].S = i;
        if (++ck[v[i].F] > k) {
            tt = true;
        }
    }
    if (tt) {
        cout << "NO\n";
        return;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)r[v[i].S] = i % k;

    cout << "YES\n";
    for (int x: r)cout << x + 1 << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

        solve();
}
