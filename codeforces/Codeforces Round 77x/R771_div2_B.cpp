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
    int n;
    cin >> n;
    vector<pi> v(n);
    int i = 0;
    for (auto &x: v)cin >> x.F, x.S = i++;
    sort(v.begin(), v.end());

    int o = -1, e = -1, ok = 1;
    for (i = 0; i < n; i++) {
        if (v[i].F % 2) {
            if (o != -1 && o > v[i].S) ok = 0;
            o = max(0, v[i].S);
        } else {
            if (e != -1 && e > v[i].S) ok = 0;
            e = max(e, v[i].S);
        }
        if (ok == 0) {
            cout << "NO\n";
            return;
        }
    }
        cout << "YES\n";

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
