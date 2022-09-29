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
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    string r(n, ' ');

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
        } else {
            if (i - k >= 0) {
                r[i - k] = '0';
            }
            if (i + k < n) {
                r[i + k] = '0';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            bool ok = false;
            if (i - k >= 0 && r[i - k] != '0') {
                r[i - k] = '1';
                ok = true;
            }
            if (!ok && i + k < n && r[i + k] != '0') {
                r[i + k] = '1';
                ok = true;
            }
            if (!ok) {
                cout << -1 << endl;
                return;
            }
        }
    }
    for (char &x: r)if (x == ' ')x = '0';
    cout << r << endl;
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
