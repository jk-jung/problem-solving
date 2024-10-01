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
    int n, m;
    cin >> n >> m;
    vi a(n + 1), b(m + 1);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;

    if (n > m) {
        if (a[0] * b[0] < 0)cout << '-';
        cout << "Infinity";
    } else if (n < m) {
        cout << "0/1";
    } else {
        if (a[0] * b[0] < 0)cout << '-';
        int g = gcd(a[0], b[0]);
        cout << ab(a[0] / g) << "/" << ab(b[0] / g);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
