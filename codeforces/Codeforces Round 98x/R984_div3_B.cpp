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
    int n, k;
    cin >> n >> k;
    map<int, int> c;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        c[a] += b;
    }
    vi t;
    for (auto [x, y]: c)t.pb(y);
    sort(t.rbegin(), t.rend());
    int r = 0;
    for (int i = 0; i < min(n, (int) t.size()); i++)r += t[i];
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
