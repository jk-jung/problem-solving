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
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;
    vi c;
    c.pb(a[0]);
    for (int i = 1; i < n; i++)c.pb(c.back() + a[i]);

    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    int r = 0;
    for (int i = 0; i < c.size(); i++) {
        int pos = i, j = 0;
        while (pos < c.size() && j < b.size()) {
            int diff1 = c[i] - c[pos];
            int diff2 = b[0] - b[j];
            if (diff1 == diff2)j++;
            pos++;
        }
        if (j == b.size()){
            r++;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
