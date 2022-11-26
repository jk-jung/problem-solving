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
    int o = 0, e = 0, m = 1 << 30;
    for (int &x: v) {
        cin >> x;
        if (x % 2)o++;
        else {
            e++;
            int t = 0;
            while (x % 2 == 0)x /= 2, t++;
            m = min(t, m);
        }
    }
    int r =0;
    if (o == 0) {
        e --;
        r += m;
    }
    cout << r + e << endl;
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
