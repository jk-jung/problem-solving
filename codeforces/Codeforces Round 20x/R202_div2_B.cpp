#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int t;
    vi v(10);
    cin >> t;
    int m = 1 << 30;
    for (int i = 1; i <= 9; i++)cin >> v[i], m = min(m, v[i]);


    string r;
    while (true) {
        bool ok = false;
        int r1 = -1, val = -1;
        for (int i = 1; i <= 9; i++) {
            if(t < v[i])continue;
            int cnt = (t - v[i]) / m;
            if (cnt >= 0 && cnt >= r1) {
                r1 = cnt;
                val = i;
                ok = true;
            }
        }
        if (ok) {
            t -= v[val];
            r += string(1, val + '0');
        }

        if (!ok)break;
    }
    if(r.empty())r = "-1";
    cout << r << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
