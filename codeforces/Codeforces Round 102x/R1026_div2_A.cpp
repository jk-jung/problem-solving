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
    vi v(n);
    for (int &x: v) cin >> x;
    sort(v.begin(), v.end());

    int r = n;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int a = v[i], b = v[i];
            for (int k = i; k <= j; k++) {
                a = min(a, v[k]);
                b = max(b, v[k]);
            }
            if ((a + b) % 2 == 0)r = min(r, n - (j - i + 1));
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
