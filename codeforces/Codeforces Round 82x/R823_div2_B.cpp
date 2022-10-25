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
    vi v(n), t(n), a;
    for (int &x: v)cin >> x;
    for (int &x: t)cin >> x;

    for (int i = 0; i < n; i++)a.pb(v[i] - t[i]), a.pb(v[i] + t[i]);
    int x = *min_element(a.begin(), a.end());
    int y = *max_element(a.begin(), a.end());
    if ((y + x) % 2) cout << (x + y) / 2 <<".5" << endl;
    else cout << (x + y) / 2 << endl;
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
