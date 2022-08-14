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
    cin >> n;
    vector<string> ab, ba;
    vi ai, bi;
    set<string> ck_a, ck_b;
    int aa = 0, bb = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s[0] == '0' && s.back() == '0')aa++;
        if (s[0] == '1' && s.back() == '1')bb++;
        if (s[0] == '0' && s.back() == '1') {
            ab.pb(s);
            ai.pb(i + 1);
            ck_a.insert(s);
        }
        if (s[0] == '1' && s.back() == '0') {
            ba.pb(s);
            bi.pb(i + 1);
            ck_b.insert(s);
        }
    }

    if (ab.size() < ba.size()) {
        swap(ab, ba);
        swap(ai, bi);
        swap(ck_a, ck_b);
    }
    int a = ab.size(), b = ba.size();
    if (a + b == 0 && aa && bb) {
        cout << -1 << endl;
        return;
    }
    vi r;
    int pos = 0;
    while (a - b > 1) {
        bool ok = false;
        for (; pos < ab.size(); pos++) {
            string &t = ab[pos];
            reverse(t.begin(), t.end());
            if (!ck_b.count(t)) {
                r.pb(ai[pos++]);
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
            return;
        }
        a--;
        b++;
    }

    cout << r.size() << endl;
    for (int x: r)cout << x << ' ';
    cout << endl;
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
