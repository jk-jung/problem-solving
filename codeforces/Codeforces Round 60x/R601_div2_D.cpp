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

string tmp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string chickens = tmp.substr(0, k);
    vector<string> v(n), r(n, string(m, chickens.back()));
    int cnt = 0;
    for (auto &s: v) {
        cin >> s;
        for (auto x: s)if (x == 'R')cnt++;
    }

    int y = 0, x = 0;
    for (char c: chickens) {
        int need = (cnt + k - 1) / k;
        k--;
        cnt -= need;

        for (; y < n; y++) {
            int dir = y % 2 == 0 ? 1 : -1;
            for (; x >= 0 && x < m; x += dir) {
                if (need == 0) break;
                if (v[y][x] == 'R')need--;
                r[y][x] = c;
            }
            if (need == 0)break;
            x = y % 2 == 0 ? m - 1 : 0;
        }
    }

    for (auto &s: r)cout << s << '\n';
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
