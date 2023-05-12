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
    for (int i = 0; i < n; i++) {
        cin >> v[i].F;
        v[i].S = i;
    }
    sort(v.rbegin(), v.rend());

    vi r;
    ll t = 0;
    for (int i = 0; i < k; i++)r.pb(v[i].S), t += v[i].F;
    sort(r.begin(), r.end());
    cout << t << endl;
    for (int i = 0; i < k; i++) {
        int x = r[i] + 1;
        if (i == k - 1)x = n;
        if (i > 0)x -= r[i - 1] + 1;
        cout << x << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
