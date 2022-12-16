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
    vi a(n), b(n), d(n + 1);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;

    for (int i = n - 1; i >= 1; i--) if (a[i] <= b[i - 1]) d[i] = d[i + 1] + 1;
    for (int x: a) cout << *lower_bound(b.begin(), b.end(), x) - x << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << b[i + d[i + 1]] - a[i] << " ";
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
