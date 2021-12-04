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
int n, m;


int calc(vector<string> &v, int s) {
    vi cur;
    int r = 0;
    for (int x = s - 2, y = 0;;) {
        if (x + 2 < m) x += 2;
        else {
            if (y == 0)y = x == m - 1 ? 0 : -1;
            y += 2, x = m - 1;
        }
        if (y >= n)break;

        for (int &k: cur)k = max(k + 1, y);
        while (!cur.empty() && cur.back() >= n)cur.pop_back();

        vi nxt, candies;
        for (int i = y, j = x; i < n && j >= 0; i++, j--)
            if (v[i][j] == '1') candies.pb(i);

        if (cur.empty()) {
            if (!candies.empty()) {
                r++;
                nxt.pb(candies.back());
            }
        } else {
            if (candies.empty()) nxt = cur;
            else {
                reverse(candies.begin(), candies.end());
                candies.pb(-1);
                int last = n + 1;
                for (int c: candies) {
                    if (c >= last) continue;
                    while (!cur.empty() && cur.back() > c) {
                        nxt.pb(cur.back());
                        cur.pop_back();
                    }
                    if (c == -1)break;
                    if (cur.empty()) last = 0, r++;
                    else {
                        last = cur.back();
                        cur.pop_back();
                    }
                    nxt.pb(c);
                }
                reverse(nxt.begin(), nxt.end());
            }
        }

        cur = nxt;
    }
    return r;
}

void solve() {
    cin >> n >> m;
    vector<string> v(n);
    for (auto &s: v)cin >> s;

    int r = calc(v, 0) + calc(v, 1);
    cout << r << endl;
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
