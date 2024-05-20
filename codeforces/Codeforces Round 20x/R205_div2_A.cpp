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
    vector<pi> v(n);
    int a = 0, b = 0;
    for (auto &[x, y]: v)cin >> x >> y, a += x, b += y;
    int r = -1;
    if (a % 2 == 0 && b % 2 == 0) r = 0;
    else if (a % 2 == 1 && b % 2 == 1) {
        for (auto [x, y]: v)if (x % 2 != y % 2) r = 1;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
