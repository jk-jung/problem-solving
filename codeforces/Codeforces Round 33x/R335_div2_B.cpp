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
    int n, m, x, y;
    set<pi> c;
    string s;

    cin >> n >> m >> x >> y;
    cin >> s;
    c.insert(mp(x, y));
    vi r = {1};
    int rest = n * m - 1;
    for (char t: s) {

        if(t == 'L')y --;
        if(t == 'R')y ++;
        if(t == 'U')x --;
        if(t == 'D')x ++;
        y = max(1, min(y, m));
        x = max(1, min(x, n));

        if(c.count(mp(x, y)))r.pb(0);
        else {
            c.insert(mp(x, y));
            r.pb(1);
            rest --;
        }

    }
    r.back() += rest;
    for (int t: r)cout << t << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
