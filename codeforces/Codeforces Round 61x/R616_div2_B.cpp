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
    vi v(n), org;
    for (int &x: v)cin >> x;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (v[i] < n - i - 1)ok = false;
    }
    if (ok) {
        cout << "Yes\n";
        return;
    }
    org = v;
    v[0] = 0;
    for (int i = 1, flag = 0; i < n; i++) {
        if (flag == 0) {
            if (v[i - 1] >= v[i]) {
                v[i - 1] = org[i - 1];
                flag = 1;
            }
            else v[i] = v[i - 1] + 1;
        }
        if (flag == 1) {
            v[i] = min(v[i - 1] - 1, v[i]);
            if (v[i] < 0) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
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
