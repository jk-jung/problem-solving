#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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
    vector<int> v(n), r(n), rr;
    vector<vector<int>> c(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
        c[v[i]].pb(i);
    }

    for (int i = 0, p = 0; i < n; i++) {
        if (c[i].size() >= k) {
            for (int j = 0; j < k; j++) r[c[i][j]] = j + 1;
        } else {
            for (int j = 0; j < c[i].size(); j++, p++)r[c[i][j]] = p % k + 1, rr.pb(c[i][j]);
        }
    }
    while (rr.size() % k != 0) {
        r[rr.back()] = 0;
        rr.pop_back();
    }

    for (int i = 0; i < n; i++) cout << r[i] << " ";
    cout << endl;
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
