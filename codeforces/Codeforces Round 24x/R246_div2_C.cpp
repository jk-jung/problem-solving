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


int p[100005];
int pos[100005];
int v[100005];

vi pp;

void pre() {
    p[0] = p[1] = 1;
    for (int i = 2; i <= 100000; i++) {
        if (p[i])continue;
        pp.pb(i - 1);
        for (int j = i + i; j <= 100000; j += i) p[j] = 1;
    }
}


vi process(int diff) {
    vi r;
    while (diff) {
        int t = lower_bound(pp.begin(), pp.end(), diff) - pp.begin();
        if(t >= pp.size() || pp[t] > diff)t--;
        diff -= pp[t];
        r.pb(pp[t]);
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> v[i], pos[v[i]] = i;

    pre();

    vector<pi> r;
    for (int i = 1; i <= n; i++) {
        if (pos[i] == i) continue;
        int x = pos[i];
        int y = i;

        vi t = process(ab(x - y));
        for (int k: t) {
            int z = x < y ? x + k : x - k;
            r.pb({min(x, z), max(x, z)});

            pos[v[z]] = x;
            pos[v[x]] = z;
            swap(v[z], v[x]);
            x = z;
        }
    }
    cout << r.size() << endl;
    for (auto i: r) cout << i.F << " " << i.S << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
