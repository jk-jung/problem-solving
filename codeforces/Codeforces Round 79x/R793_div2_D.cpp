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
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (char x: s)if (x == '1') cnt++;

    if (cnt == 0 || cnt % 2) {
        cout << "NO\n";
        return;
    }

    s = s + s;
    int idx = 0;
    for (int i = 1; i < n * 2; i++) {
        if (s[i - 1] == '1' && s[i] == '0') {
            idx = i;
            break;
        }
    }

    vector<pi> r;
    int last = -1;
    for (int i = idx + 1; i < idx + n; i++) {
        if (last != -1) {
            r.pb({last, i % n});
            last = -1;
        } else {
            r.pb({idx % n, i % n});
        }

        if (s[i] == '0')last = i % n;
    }
    cout << "YES\n";
    for (auto [x, y]: r)cout << x + 1 << " " << y + 1 << '\n';
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
