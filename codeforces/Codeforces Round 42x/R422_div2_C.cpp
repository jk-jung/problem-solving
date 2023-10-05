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

class Data {
public:
    int s, e, c;
};

bool sf1(Data &a, Data &b) { return a.s < b.s; }

bool sf2(Data &a, Data &b) { return a.e < b.e; }

map<int, int> cc;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<Data> v(n), ss, ee;
    vi vs(n), ve(n), s(n), e(n);
    for (auto &x: v) cin >> x.s >> x.e >> x.c;
    ss = v;
    ee = v;
    sort(ss.begin(), ss.end(), sf1);
    sort(ee.begin(), ee.end(), sf2);

    int i = 0;
    ll r = 1e18;
    for (auto x: ss) {
        while (i < n && ee[i].e < x.s) {
            int t = ee[i].e - ee[i].s + 1;
            if (t > 0) {
                if (cc.count(t)) cc[t] = min(cc[t], ee[i].c);
                else cc[t] = ee[i].c;
            }
            i++;
        }

        int t = k - x.e + x.s - 1;
        if (cc.count(t)) {
            r = min(r, (ll)cc[t] + x.c);
        }
    }

    if (r == 1e18)r = -1;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
