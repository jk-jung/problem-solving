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
    vi a, b;
    ll r = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2)a.pb(x);
        else b.pb(x), r += x;
    }
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    while (a.size() && a.size() % 2 == 0)a.pop_back();
    if (a.size() % 2) {
        for (int x: a) r += x;
        cout << r;
    } else cout << 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
