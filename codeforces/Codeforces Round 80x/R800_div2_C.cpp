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
    ll s = 0;
    cin >> n;
    vector<ll> v(n);
    for (ll &x: v)cin >> x, s += x;
    while (!v.empty() && v.back() == 0)v.pop_back();

    if (v.empty() || (s == 0 && v[0] > 0 && v.back() < 0)) {
        ll st = 0;
        while (!v.empty()) {
            st += v.back();
            v.pop_back();
            if(!v.empty() && st >= 0) {
                cout <<"No\n";
                return;
            }
        }
        cout <<"Yes\n";
    } else {
        cout << "No\n";
    }
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
