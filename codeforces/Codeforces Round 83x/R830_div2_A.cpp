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
    int g = 0;
    for (int &x: v)cin >> x, g = gcd(g, x);

    int r = 3;
    if(g == 1)r = 0;
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int k = 0; k < n; k++) {
            int x = v[k];
            if (k == i) x = gcd(x, i + 1);
            t = gcd(t, x);
        }
        if (t == 1)r = min(r, n - i);
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
