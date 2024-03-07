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
    for (int i = 1; i <= n; i++) {
        cin >> v[i - 1].F;
        v[i - 1].S = i;
    }
    sort(v.begin(), v.end());
    vi r;
    for(auto [x, y]: v) {
        if(k >= x) {
            k -= x;
            r.pb(y);
        }
    }
    cout << r.size() << endl;
    for(auto x: r) cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
