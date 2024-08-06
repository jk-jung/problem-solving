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
    vi a, b;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x % 2)a.pb(x);
        else b.pb(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int r = 0;
    if (!a.empty() && !b.empty()) {
        ll t = a.back();
        r += b.size();
        for (int x: b) {
            if (t < x) {
                r++;
                break;
            }
            t += x;
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
