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

int n;
string s;

pair<int, string> f(map<char, int> ck, int k, string ss) {
    if (k == 5) {
        k = k;
    }
    int mm = n / k;
    int need = mm - (int) ck.size();
    if (mm > 26) return mp(1 << 30, "");
    int r = 0;
    for (auto [x, y]: ck) r += max(0, y - k);

    vector<pair<int, char>> a, b, c;
    for (auto [x, y]: ck) {
        if (y > k)a.pb(mp(y - k, x));
        else if (y < k) b.pb(mp(y, x));
    }

    sort(a.rbegin(), a.rend());

    vector<char> tr[255];
    for (auto &[cnt, x]: a) {
        while (cnt > 0 && need > 0) {
            for (char y = 'a'; y <= 'z'; y++) {
                if (!ck.count(y)) {
                    tr[x].pb(y);
                    cnt--;
                    need--;
                    ck[y] = 1;
                    if (k != 1) b.pb(mp(1, y));
                    break;
                }
            }
        }
    }
    sort(b.begin(), b.end());
    for (auto [cnt, x]: a) {
        while (cnt > 0) {
            auto &[c2, y] = b.back();
            while (c2 < k && cnt > 0) {
                tr[x].pb(y);
                c2++;
                cnt--;
            }
            if (c2 == k)b.pop_back();
        }
    }
    while (!b.empty()) {
        auto &[c1, x] = b.back();
        auto &[c2, y] = b[0];
        // c2 -> c1;
        int t = min(k - c1, c2);
        c1 += t;
        c2 -= t;
        r += t;
        while (t--) {
            tr[y].pb(x);
        }
        if (c2 == 0) {
            c.clear();
            for (int i = 1; i < b.size(); i++)c.pb(b[i]);
            b = c;
        }
        if (c1 == k) b.pop_back();
    }

    for (char &x: ss) {
        if (!tr[x].empty()) {
            char y = x;
            x = tr[y].back();
            tr[y].pop_back();
        }
    }

    return mp(r, ss);
}

void solve() {
    cin >> n >> s;
    map<char, int> ck;
    for (char x: s)ck[x]++;

    pair<int, string> r = {n, ""};
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            r = min(r, f(ck, i, s));
            r = min(r, f(ck, n / i, s));
        }
    }
    cout << r.F << endl << r.S << endl;
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
