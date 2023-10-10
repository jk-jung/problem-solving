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
    vi v(n);
    int tot = 0;
    for (int &x: v)cin >> x, tot += x;
    sort(v.begin(), v.end());
    int m;
    cin >> m;
    vector<pi> t(m);
    for (auto &[x, y]: t)cin >> x >> y;

    for (auto &[x, y]: t) {
        if (x <= tot && tot <= y) {
            cout << tot << endl;
            return;
        } else if (x >= tot) {
            cout << x << endl;
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
