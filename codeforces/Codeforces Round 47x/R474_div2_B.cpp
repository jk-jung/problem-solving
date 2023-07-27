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
    int n, A, B;
    cin >> n >> A >> B;
    vi a(n), b(n), v(n);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;
    for (int i = 0; i < n; i++)v.pb(ab(a[i] - b[i]));
    A += B;
    while (A--) {
        sort(v.begin(), v.end());
        v.back() = ab(v.back() - 1);
    }
    ll r = 0;
    for (int x: v)r += ll(x) * x;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
