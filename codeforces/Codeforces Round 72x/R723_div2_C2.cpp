#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

vector<int> v;

class DSU {
public:
    vector<int> p;

    DSU(int n = -1) {
        if (n > 0)init(n);
    }

    void init(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) { return p[x] != x ? p[x] = find(p[x]) : x; }

    void unite(int x, int y) { p[find(y)] = p[find(x)]; }
} dsu;


bool check(pi x, bool update = false) {
    int r = x.F;
    for (int i = -x.S; i >= 0; i--) {
        int next = dsu.find(i);

        if (v[next] >= 0) {
            int dif = min(r, v[next]);
            r -= dif;
            if (update) {
                v[next] -= dif;
                if (v[next] == 0 && next > 0)
                    dsu.unite(next - 1, next);
            }
        } else if (update) {
            dsu.unite(next - 1, next);
        }

        if (r == 0)return true;
        i = next;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r = 0;
    cin >> n;
    vector<pi> v2;
    v.resize(n);
    dsu.init(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] < 0) {
            v2.pb({-v[i], -i});
            if (i > 0) dsu.unite(i - 1, i);
        } else {
            r++;
        }
    }
    sort(v2.begin(), v2.end());

    int last = -1;
    for (int i = 0; i < v2.size(); i++) {
        if (-v2[i].S < last) continue;
        if (check(v2[i])) {
            check(v2[i], true);
            r++;
        } else {
            last = -v2[i].S;
        }
    }

    cout << r << endl;
}
