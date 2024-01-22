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
    vi v(n + 1), c(n + 3), d(n + 2);
    for (int i = 1; i <= n; i++)cin >> v[i], c[v[i]] = i;
    int r = 0;
    for (int i = n; i >= 1; i--) {
        if (i < c[v[i] + 1])d[i] = d[c[v[i] + 1]] + 1;
        else d[i] = 1;
        r = max(r, d[i]);
    }
    cout << n - r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
