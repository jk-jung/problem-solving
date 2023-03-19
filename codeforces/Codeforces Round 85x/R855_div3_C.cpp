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
    int n;
    cin >> n;
    set<int> ck;
    vector<pi> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x)v.pb({x, i});
        else ck.insert(i);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    ll r = 0;
    for (auto [x, i]: v) {
        auto t = ck.lower_bound(i);
        if (ck.end() != t) {
            r += x;
            ck.erase(t);
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
