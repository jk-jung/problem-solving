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
    map<string, int> ck;
    for (int i = 0; i < n; i++) {
        int x;
        string s;
        cin >> x >> s;
        sort(s.begin(), s.end());
        if (!ck.count(s))ck[s] = x;
        else ck[s] = min(ck[s], x);
    }
    int r = 1 << 30;

    vector<pair<string, int>> t;
    for (auto &i1: ck) {
        t.pb({i1.F, i1.S});
        for (auto &i2: ck) {
            t.pb({i1.F + i2.F, i1.S + i2.S});
            for (auto &i3: ck) {
                t.pb({i1.F + i2.F + i3.F, i1.S + i2.S + i3.S});
            }
        }
    }
    for (auto &[x, y]: t) {
        sort(x.begin(), x.end());
        x.erase(unique(x.begin(), x.end()), x.end());
        if (x.size() == 3)r = min(r, y);
    }

    if (r == (1 << 30)) r = -1;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
