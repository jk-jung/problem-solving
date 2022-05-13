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
    int n, k, x;
    cin >> n >> k;
    map<int, int> ck;
    while (n--) {
        cin >> x;
        ck[x]++;
    }
    int r1 = -1, r2 = -1, last = -1, before = -1;
    for (auto [t, v]: ck) {
        if (v < k) last = -1;
        else if (last == -1 || before + 1 != t)
            last = t;
        if (last != -1 && t - last >= r2 - r1) {
            r2 = t;
            r1 = last;
        }
        before = t;
    }
    if (r1 == -1)cout << -1 << endl;
    else cout << r1 << " " << r2 << endl;
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
