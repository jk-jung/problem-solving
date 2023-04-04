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


int f(pi x) { return x.S - x.F + 1; }

void solve() {
    int n;
    string s;
    cin >> n >> s;

    s = 'S' + s;
    vector<pi> v;
    int r = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'G') {
            if (s[i - 1] == 'S')v.pb(mp(i, i));
            else v.back().S = i;

            r = max(r, f(v.back()));
        }
    }

    if (v.size() >= 2)r++;
    for (int i = 1; i < v.size(); i++) {
        if (v[i - 1].S + 2 == v[i].F) {
            if (v.size() >= 3) r = max(r, f(v[i - 1]) + f(v[i]) + 1);
            else r = max(r, f(v[i - 1]) + f(v[i]));
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
