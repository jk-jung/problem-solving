#include <string.h>
#include <stdio.h>
#include <math.h>
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
    vi v(n), ck(k * 3);
    for (int &x: v)cin >> x;

    for (int i = 0; i < n / 2; i++) {
        int a = min(v[i], v[n - i - 1]);
        int b = max(v[i], v[n - i - 1]);

        if (b == 1) {
        } else if (a == 1) {
            ck[2] += 1;
            ck[a + b] += -1;
        } else {
            ck[2] += 2;
            ck[a + 1] += -1;
            ck[a + b] += -1;
        }
        ck[a + b + 1] += 1;
        ck[k + b + 1] += 1;
    }
    int r = 1 << 30;
    for (int i = 2, s = 0; i <= k * 2; i++) {
        s += ck[i];
        r = min(r, s);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
