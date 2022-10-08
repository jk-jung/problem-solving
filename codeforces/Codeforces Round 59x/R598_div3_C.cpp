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
    int n, m, d;
    cin >> n >> m >> d;;
    vi v(m), r(n);
    int s = 0;
    for (int &x: v)cin >> x, s += x;

    int pos = -1, idx = 1;
    for (int x: v) {
        int nt = pos + d;
        if (nt + s - 1 >= n) nt = n - s;

        pos = nt + x - 1;
        s -= x;
        for (int i = 0; i < x; i++)r[nt + i] = idx;
        idx++;
    }
    if (pos + d >= n) {
        cout << "YES\n";
        for (int x: r)cout << x << " ";
        cout << endl;
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
