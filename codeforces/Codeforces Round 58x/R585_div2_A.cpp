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
    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    int m = min(a1 + a2, n - (k1 - 1) * a1 - (k2 - 1) * a2);
    if (k1 > k2) swap(k1, k2), swap(a1, a2);
    int r = 0;
    while (n >= k1 && a1)a1--, n -= k1, r++;
    while (n >= k2 && a2)a2--, n -= k2, r++;
    cout << max(0, m) << " " << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
