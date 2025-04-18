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


int a[55], b[55];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n * (n - 1) / 2 - 1; i++) {
        int x, y;
        cin >> x >> y;
        a[x]++;
        b[y]++;
    }
    vi v;
    for (int i = 1; i <= n; i++)if (a[i] + b[i] != n - 1)v.pb(i);
    if (a[v[0]] < a[v[1]])swap(v[0], v[1]);
    cout << v[0] << " " << v[1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
