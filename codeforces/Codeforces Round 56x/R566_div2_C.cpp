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
    map<pair<int, char>, vector<string>> ck;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        char x = ' ';
        int cnt = 0;
        for (char y: s)if (y == 'a' || y == 'e' || y == 'i' || y == 'o' || y == 'u') x = y, cnt++;
        ck[mp(cnt, x)].pb(s);
    }
    vector<pair<string, string>> a, b;
    vector<pair<pair<string, string>, pair<string, string>>> r;
    map<int, vector<string>> ck2;
    for (auto [x, y]: ck) {
        int m = y.size();
        if (m % 2) ck2[x.F].pb(y[0]);
        for (int i = m % 2; i + 1 < m; i += 2) {
            b.pb({y[i], y[i + 1]});
        }
    }
    for (auto [x, y]: ck2) {
        int m = y.size();
        for (int i = 0; i + 1 < m; i += 2) {
            a.pb({y[i], y[i + 1]});
        }
    }
    for (int i = 0; i < b.size(); i++) {
        if (!a.empty()) {
            r.pb({a.back(), b[i]});
            a.pop_back();
        } else if (i + 1 < b.size()) {
            r.pb({b[i], b[i + 1]});
            i++;
        }
    }
    cout << r.size() << endl;
    for (auto [x, y]: r) {
        cout << x.F <<" " << y.F << '\n';
        cout << x.S <<" " << y.S << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
