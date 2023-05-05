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
    int n, a, b;
    cin >> n >> a >> b;
    vi v(n);
    for (int &x: v)cin >> x;

    int r = 0;
    for (int s = 0, e = n - 1; s <= e; s++, e--) {
        int t = v[s] + v[e];
        if (s == e) {
            if (t == 4)r += min(a, b);
            continue;
        }
        if (t == 4) r += min(a, b) * 2;
        else if (t == 3) r += b;
        else if (t == 0);
        else if (t == 1) {
            cout << "-1\n";
            return;
        } else if (v[s] == 1 && v[e] == 1);
        else r += a;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
