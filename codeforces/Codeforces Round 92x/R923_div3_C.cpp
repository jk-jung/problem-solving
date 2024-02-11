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
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    map<int, int> aa, bb;
    for (int &x: a) cin >> x, aa[x] = 1;
    for (int &x: b) cin >> x, bb[x] = 1;;
    int ca = 0, cb = 0;
    for (int i = 1; i <= k; i++) {
        bool x = aa.count(i);
        bool y = bb.count(i);
        if (!x && !y) {
            cout << "NO" << endl;
            return;
        }
        if (x && y) {
        } else if (x) {
            ca++;
        } else {
            cb++;
        }
        if(ca > k / 2 || cb > k / 2) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
