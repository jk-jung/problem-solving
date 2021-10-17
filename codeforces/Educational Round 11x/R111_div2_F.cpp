#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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

const int BASE = 1100000;
const int S = 0, E = 3300000;

class IndexTree {
public:
    int n, size;
    vector<int> d;

    IndexTree(int _n) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        size = 1 << (32 - __builtin_clz(n));
        d.resize(size * 2 + 5);
    }

    void up(int x, int v) {
        x += size;
        while (x) d[x] += v, x >>= 1;
    }

    int read(int s, int e) {
        s += size, e += size;
        int r = 0;
        while (s <= e) {
            if ((s & 1) == 1) r += d[s++];
            if ((e & 1) == 0) r += d[e--];
            s >>= 1, e >>= 1;
        }
        return r;
    }

    int kth(int k) {
        int x = 1;
        while (x < size) {
            if (d[x * 2] < k) k -= d[x * 2], x = x * 2 + 1;
            else x *= 2;
        }
        return x - size;
    }

    int check(int s, int e) {
        if (read(s, e) == 0) return -1;
        int ss = s, r = -1;
        while (s <= e) {
            int m = (s + e) / 2;
            if (read(ss, m) > 0)r = m, e = m - 1;
            else s = m + 1;
        }
        return r;
    }
} tre(E + 5);

int n, q, s, d;
int a[200005], ra[E], vis[E];


struct Query {
    int id, target, dist, answer = 0;

    static bool sf1(Query &q1, Query &q2) { return q1.dist < q2.dist; }

    static bool sf2(Query &q1, Query &q2) { return q1.id < q2.id; }
};

bool can_go(int y, queue<pi> &q1) {
    if (vis[y]) return false;
    vis[y] = 1;
    if (ra[y]) q1.push({0, y});
    return true;
}

void proceed(int k, queue<pi> &q1, queue<pi> &q2) {
    int di[] = {-1, 1};
    while (!q1.empty()) {
        auto[ty, x] = q1.front();
        q1.pop();

        if (ty == 0) {
            for (int z: {x - d, x + d}) {
                while(true){
                    int y = tre.check(z - k, z + k);
                    if( y == -1)break;
                    tre.up(y, -1);
                    vis[y] = 1;
                    if (ra[y]) q1.push({0, y});
                }
                q2.push({1, z - k});
                q2.push({1, z + k});
            }
        } else {
            for (int i: di) {
                int y = x + i;
                if (y <= S || y >= E || vis[y]) continue;
                tre.up(y, -1);
                vis[y] = 1;
                q2.push({1, y});
                if (ra[y]) q1.push({0, y});
            }
        }
    }
}

void solve() {
    cin >> n >> q >> s >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], a[i] += BASE;
        ra[a[i]] = 1;
    }

    vector<Query> vq(q);
    for (int i = 0; i < q; i++) {
        vq[i].id = i;
        cin >> vq[i].target >> vq[i].dist;
    }
    sort(vq.begin(), vq.end(), Query::sf1);

    queue<pi> q1, q2;
    q1.push({0, a[s]});
    for (int k = 0, pos = 0; k <= 1000000; k++) {
        proceed(k, q1, q2);
        swap(q1, q2);

        while (pos < q && vq[pos].dist == k) {
            int t = vq[pos].target;
            if (t == s || vis[a[t]]) vq[pos].answer = 1;
            pos++;
        }
        if (pos == q)break;
    }

    sort(vq.begin(), vq.end(), Query::sf2);
    for (auto x: vq) cout << (x.answer ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < E; i++) tre.up(i, 1);

    solve();
}
