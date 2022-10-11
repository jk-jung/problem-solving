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
    int n, t, cnt = 0, s = 0;
    cin >> n >> t;
    vi v(n);
    for (int &x: v)cin >> x, cnt += x == t, s += x;
    if (cnt == n) {
        cout << 0 << endl;
    } else {
        if (cnt > 0) {
            cout << 1 << endl;
        } else {
            if (s % n == 0 && s / n == t) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        }
    }
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
