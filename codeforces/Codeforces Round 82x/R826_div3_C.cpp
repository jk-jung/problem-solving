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
    int n, s = 0;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x, s += x;

    int r = n;
    for (int k = 2; k <= n; k++) {
        if (s % k) continue;
        int t = s / k;
        int tmp = 0, ss = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            ss += v[i];
            cnt++;
            if (ss > t) {
                tmp = 1 << 30;
                break;
            } else if (ss == t) {
                tmp = max(tmp, cnt);
                cnt = 0;
                ss = 0;
            }
        }
        r = min(r, tmp);
    }
    cout << r << endl;
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
