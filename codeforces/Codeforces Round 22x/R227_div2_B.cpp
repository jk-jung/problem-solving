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
    vi a(n);
    vi b(m);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;
    int r = 0;
    for (int i = n - 1; i >= 0; i--) {
        int x = a[i];
        if (!b.empty() && b.back() >= x)b.pop_back();
        else r++;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
