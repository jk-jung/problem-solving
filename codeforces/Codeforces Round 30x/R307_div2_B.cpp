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
    string a, b, c;
    map<int, int> aa, bb, cc;
    cin >> a >> b >> c;
    for (char x: a)aa[x]++;
    for (char x: b)bb[x]++;
    for (char x: c)cc[x]++;

    int r = 0, idx = 0;
    for (int i = 0;; i++) {
        bool ok = true;
        map<int, int> t = aa;
        for (auto [x, y]: bb) {
            t[x] -= y * i;
            if (t[x] < 0) {
                ok = false;
                break;
            }
        }
        if (!ok)break;
        int j = 1 << 30;
        for (auto [x, y]: cc) j = min(j, t[x] / y);

        if (r < i + j) {
            r = i + j;
            idx = i;
        }
    }

    for (int i = 0; i < idx; i++) cout << b;
    for (auto [x, y]: bb) aa[x] -= y * idx;

    for (int i = 0; i < r - idx; i++) cout << c;
    for (auto [x, y]: cc) aa[x] -= y * (r - idx);

    for (auto [x, y]: aa)cout << string(y, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
