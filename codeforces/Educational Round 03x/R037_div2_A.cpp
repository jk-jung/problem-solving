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
    int n, k;
    cin >> n >> k;
    vi v(k), r(n + 1);
    for (int &x: v)cin >> x;

    for (int i = 0;; i++) {
        bool ok = true;
        for (int j = 1; j <= n; j++) {
            bool ck = false;
            for (int x: v) {
                if (ab(x - j) <= i)ck = true;
            }
            if (!ck) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << i + 1 << endl;
            return;
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
