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
    string s, r;
    cin >> n >> s;
    for (int i = n - 1, t = 0; i >= 0; i--) {
        int k = s[i] - '0' + t;
        if (k < 2) {
            r += char(1 - k + '0');
            t = 0;
        } else {
            r += char(11 - k + '0');
            t = 1;
        }
    }
    reverse(r.begin(), r.end());
    if (r[0] == '0') {
        r.clear();
        for (int i = n - 1; i >= 0; i--) {
            r += char('9' - s[i] + '0');
        }
        reverse(r.begin(), r.end());
    }
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
