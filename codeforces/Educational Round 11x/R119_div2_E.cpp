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

vi v[500005];

void solve() {
    int q;
    cin >> q;

    int n = 0;
    while (q--) {
        int a, b, c;
        cin >> a >> b;
        if (a == 1) v[b].pb(n++);
        else {
            cin >> c;
            if(b == c) continue;
            bool sw = v[b].size() > v[c].size();
            if (sw) swap(b, c);
            for (int x: v[b])v[c].pb(x);
            v[b].clear();
            if (sw) swap(v[b], v[c]);
        }
    }
    vi r(n);
    for (int i = 0; i <= 500000; i++)
        for (int x: v[i])r[x] = i;

    for(int &x: r)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
