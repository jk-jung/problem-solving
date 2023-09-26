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
    vi v(n);
    for (int &x: v)cin >> x;

    ll r = 0, m = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 && v[i] < 0) {
            for (int j = i; j < n; j++)r += max(0, v[j]);
            break;
        }
        m = i;
    }
    ll t = 0, s = 0;
    for (int i = m; i >= 0; i --) {
        if(i % 2 == 0) {
            t = max(t, s + v[i]);
        }else {
            t = max(t, s);
        }
        s += max(0, v[i]);
    }
    cout << r + t << endl;
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
