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
    vi a(n);
    for (int &x: a)cin >> x;
    vi b = a;
    sort(b.begin(), b.end());
    vector<ll> A(1), B(1);
    for (int i = 0; i < n; i++) {
        A.pb(A.back() + a[i]);
        B.pb(B.back() + b[i]);
    }
    int m;
    cin >> m;
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        vector<ll> &c = (x == 1 ? A : B);
        cout << c[z] - c[y - 1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
