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


void in(vector<set<int>> &v, bool rev = false) {
    int n, x, y;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        x--, y--;
        if (rev)swap(x, y);
        v[y].insert(x);
    }
}


void in2(vector<pi> &v) {
    for (int i = 0; i < v.size(); i++)cin >> v[i].F, v[i].S = i;
    sort(v.begin(), v.end());
}

void calc(vector<pi> &aa, vector<pi> &bb, vector<set<int>> &c, vector<pi> &r) {
    for (auto b: bb) {
        for (auto a: aa) {
            if (!c[b.S].count(a.S)) {
                r.pb({a.F + b.F, b.S});
                break;
            }
        }
    }
    sort(r.begin(), r.end());
}

void solve() {
    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;
    vector<pi> v1(n1), v2(n2), v3(n3), v4(n4);
    in2(v1), in2(v2), in2(v3), in2(v4);

    vector<set<int>> t1(n2), t2(n3), t3(n3);
    in(t1), in(t2), in(t3, true);

    vector<pi> v12, v34, r;
    calc(v1, v2, t1, v12);
    calc(v4, v3, t3, v34);
    calc(v12, v34, t2, r);

    int rst = 1 << 30;
    for (auto[x, y]: r)rst = min(rst, x);
    if (rst == (1 << 30))rst = -1;
    cout << rst << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
