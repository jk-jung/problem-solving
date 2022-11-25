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
    int l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;
    if (a == b)cout << 0 << endl;
    else if (ab(a - b) >= x) cout << 1 << endl;
    else {
        int t = -1;
        bool al = ab(a - l) >= x;
        bool ar = ab(a - r) >= x;
        bool lr = ab(l - r) >= x;
        bool lb = ab(b - l) >= x;
        bool rb = ab(b - r) >= x;

        if (al && lb) t = 2;
        else if (ar && rb) t = 2;
        else if (ar && lr && lb) t = 3;
        else if (al && lr && rb) t = 3;

        cout << t << endl;
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
