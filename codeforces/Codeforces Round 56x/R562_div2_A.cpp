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
    int n, a, x, b, y;
    cin >> n >> a >> x >> b >> y;
    int ok = 0;
    while (true) {
        if (a == b)ok = 1;
        if (a == x || b == y) break;
        a++;
        b--;
        if (a == n + 1) a = 1;
        if (b == 0) b = n;

    }
    cout << (ok ? "YES" : "NO\n") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
