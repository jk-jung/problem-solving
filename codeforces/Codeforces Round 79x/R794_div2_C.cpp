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
    int n, m = 0;
    cin >> n;
    vi v(n);
    map<int, int> ck;
    for (int &x: v)cin >> x, m = max(m, ++ck[x]);
    if (n % 2 || m > n / 2) {
        cout << "NO\n";
        return;
    }
    if (m == n / 2 && ck.begin()->S != m && ck.rbegin()->S != m) {
        cout << "NO\n";
        return;
    }
    sort(v.begin(), v.end());
    cout << "YES\n";
    vi r(n);

    int k = 0;
    for (int i = 0; i < n; i += 2, k++)r[i] = v[k];
    for (int i = 1; i < n; i += 2, k++)r[i] = v[k];
    for (int x: r)cout << x << " ";
    cout << endl;
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
