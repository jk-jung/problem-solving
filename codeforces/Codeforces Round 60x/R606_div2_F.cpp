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
    map<int, int> ck;
    for (int i = 0, x; i < n; i++)cin >> x, ck[x]++;

    vector<pi> v;
    for (auto [x, y]: ck)v.pb({y, x});
    sort(v.begin(), v.end());

    int pos = 0, ra = 0, rb = 0, sz = 0;
    for (int a = 1, b; a <= n; a++) {
        while (pos < v.size() && v[pos].F < a)pos++;
        sz += int(v.size()) - pos;
        b = sz / a;
        if (a <= b && a * b > ra * rb) {
            ra = a;
            rb = b;
        }
    }
    vector<vi> r(ra, vi(rb));
    pos = int(v.size()) - 1;
    for (auto &[x, y]: v)x = min(x, ra);
    for (int i = 0, x = 0, y = 0; i < ra * rb; i++) {
        if (v[pos].F == 0)pos--;
        if (r[y][x]) x = (x + 1) % rb;
        r[y][x] = v[pos].S;
        v[pos].F--;
        y = (y + 1) % ra;
        x = (x + 1) % rb;
    }

    cout << ra * rb << endl;
    cout << ra << " " << rb << endl;
    for (int i = 0; i < ra; i++) {
        for (int j = 0; j < rb; j++)cout << r[i][j] << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
