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
    cin >> m >> n;
    vi r;
    int s = n / 2, e = s + 1;
    if (n % 2)r.pb(e++);
    for (; s >= 1; s--, e++) {
        r.pb(s);
        r.pb(e);
    }
    for (int i = 0; i < m; i++)cout << r[i % n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
