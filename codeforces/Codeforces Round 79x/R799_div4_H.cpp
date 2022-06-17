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


vi calc(int k, vi &v) {
    int n = v.size(), r = 1, s = v[0] + 1, e = v[0] + 1, rs = v[0] + 1;
    for (int i = 1, last = 1; i < n; i++) {
        int nt = last - v[i] + v[i - 1] + 1;
        if (nt > 0) last = nt + 1;
        else last = 1, s = v[i] + 1;

        if (last > r) {
            r = last;
            rs = s;
            e = v[i] + 1;
        }
        r = max(r, last);
    }
    return {r, k, rs, e};
}

void solve() {
    int n;
    cin >> n;
    map<int, vi> ck;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        ck[x].pb(i);
    }
    vi r = {0, 0, 0, 0};
    for (auto &[k, v]: ck){
        r = max(r, calc(k, v));
    }
    cout << r[1] << " " << r[2] << " " << r[3] << endl;
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
