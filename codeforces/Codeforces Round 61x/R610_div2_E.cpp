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

class Point {
public:
    Point *right;
    int x;

    Point() {}

    Point(int _x) : x(_x) {
        right = nullptr;
    }
};

class Points {
public:

    Point *start;
    map<pi, Point *> sides;

    Points(int x, int y, int z) {
        auto *a = new Point(x);
        auto *b = new Point(y);
        auto *c = new Point(z);
        start = a;
        a->right = b;
        b->right = c;
        c->right = a;
        add_side(x, y, a);
        add_side(y, z, b);
        add_side(x, z, c);
    }

    void add(int x, int y, int z) {
        Point *a = sides[{x, y}];
        Point *b = a->right;
        auto *c = new Point(z);

        a->right = c;
        c->right = b;

        add_side(a->x, z, a);
        add_side(z, b->x, c);
    }

    void add_side(int x, int y, Point *p) {
        sides[{min(x, y), max(x, y)}] = p;
    }
};

void add_triangle(Points *p, int zz, tuple<int, int, int> tri) {
    auto [x, y, z] = tri;
    int a = x, b = y;
    if (zz == x) a = y, b = z;
    if (zz == y) a = x, b = z;
    if (zz == z) a = x, b = y;

    p->add(a, b, zz);
}

void solve() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> v;
    map<pi, set<pi>> sides;
    vector<set<int>> cnt(n + 1);
    for (int i = 0, x, y, z; i < n - 2; i++) {
        cin >> x >> y >> z;
        if (x > y)swap(x, y);
        if (y > z)swap(y, z);
        if (x > y)swap(x, y);
        v.pb({x, y, z});
        cnt[x].insert(i);
        cnt[y].insert(i);
        cnt[z].insert(i);
        sides[{x, y}].insert({i, z});
        sides[{y, z}].insert({i, x});
        sides[{x, z}].insert({i, y});
    }
    vi q;
    queue<int> qq;
    vi used(n+1);
    for (int i = 1; i <= n; i++)if (cnt[i].size() == 1)qq.push(*cnt[i].begin());
    while (!qq.empty()) {
        int k = qq.front();
        qq.pop();
        if(used[k])continue;
        used[k] = 1;
        q.pb(k);

        auto [x, y, z] = v[k];
        cnt[x].erase(k);
        cnt[y].erase(k);
        cnt[z].erase(k);

        if(cnt[x].size() == 1)qq.push(*cnt[x].begin());
        if(cnt[y].size() == 1)qq.push(*cnt[y].begin());
        if(cnt[z].size() == 1)qq.push(*cnt[z].begin());
    }
    auto [a, b, c] = v[q[0]];
    auto *ps = new Points(a, b, c);
    queue<int> tt;
    tt.push(q[0]);
    for (int i = 0; i < n - 2; i++) {
        int idx = tt.front();
        tt.pop();
        auto [x, y, z] = v[idx];
        sides[{x, y}].erase({idx, z});
        sides[{y, z}].erase({idx, x});
        sides[{x, z}].erase({idx, y});

        pi nxt;
        if (sides[{x, y}].size() == 1) {
            nxt = *sides[{x, y}].begin();
            add_triangle(ps, nxt.S, v[nxt.F]);
            tt.push(nxt.F);
        }
        if (sides[{y, z}].size() == 1) {
            nxt = *sides[{y, z}].begin();
            add_triangle(ps, nxt.S, v[nxt.F]);
            tt.push(nxt.F);
        }
        if (sides[{x, z}].size() == 1) {
            nxt = *sides[{x, z}].begin();
            add_triangle(ps, nxt.S, v[nxt.F]);
            tt.push(nxt.F);
        }
    }

    Point *pp = ps->start;
    int xx = pp->x;
    while (true) {
        cout << pp->x << " ";
        pp = pp->right;
        if (pp->x == xx)break;
    }
    cout << '\n';
    for (int x: q)cout << x + 1 << " ";
    cout << '\n';
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
