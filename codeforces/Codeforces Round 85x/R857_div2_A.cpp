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
    int a = 0, b = 0;
    for (int &x: v)cin >> x;
    for (int x: v) {
        if (x > 0)a++;
        else b++;
    }
    for (int i = 1; i <= n; ++i) {
        if (i <= a) cout << i << ' ';
        else cout << a * 2 - i << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= n; ++i) {
        if (i <= b * 2) cout << i % 2 << ' ';
        else cout << (i - b * 2) << ' ';
    }
    cout << '\n';
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
