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
    vi v(n), e(k);
    for (int &x: v)cin >> x;
    for (int &x: e)cin >> x;
    sort(v.begin(), v.end());
    sort(e.begin(), e.end());

    ll r = 0;
    for (int x: e) {
        ll t = v.back();
        if (x == 1) t *= 2;
        r += t;
        v.pop_back();
    }
    reverse(v.begin(), v.end());
    reverse(e.begin(), e.end());
    for (int x: e) {
        if (x >= 2) {
            r += v.back();
            while (x >= 2) {
                x--;
                v.pop_back();
            }
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
