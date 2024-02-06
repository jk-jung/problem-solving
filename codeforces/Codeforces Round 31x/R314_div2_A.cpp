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
    vector<pi> v(n);
    for (int i = 0; i < n; i++)cin >> v[i].F, v[i].S = i;
    sort(v.begin(), v.end());
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
        a[v[i].S] = min(ab(v[i].F - v[(i - 1 + n) % n].F), ab(v[i].F - v[(i + 1) % n].F));
        b[v[i].S] = max(ab(v[i].F - v[0].F), ab(v[i].F - v[n - 1].F));
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " << b[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
