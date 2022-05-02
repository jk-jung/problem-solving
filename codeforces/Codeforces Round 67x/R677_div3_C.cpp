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
    int n, t = 0;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x, t = max(t, x);

    for (int i = 0; i < n; i++) {
        if (v[i] == t) {
            if ((i && v[i - 1] != t) || (i != n - 1 && v[i + 1] != t)) {
                cout << i + 1 << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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
