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
    vi v(n), d(n), s(n, -1), e(n), last(n), ck(5001, -1), rck(5001, -1);
    for (int &x: v)cin >> x;

    for (int i = 0; i < n; i++) {
        int x = v[i];
        if (ck[x] == -1)ck[x] = i;
        s[i] = ck[x];
    }
    for (int i = n - 1; i >= 0; i--) {
        int x = v[i];
        if (rck[x] == -1)rck[x] = i, last[i] = 1;
        e[i] = rck[x];
    }

    int r = 0;
    for (int i = 0; i < n; i++) {
        if (i)d[i] = d[i - 1];
        if (!last[i]) continue;
        int j = i, x = 0, ok = 1;
        set<int> t;
        for (int ss = s[i]; j >= ss; j--) {
            ss = min(ss, s[j]);
            if (!t.count(v[j])) {
                t.insert(v[j]);
                x ^= v[j];
            }
            if(e[j] > i){
                ok = 0;
                break;
            }
        }
        if(!ok)continue;
        d[i] = max(d[i], x + (j >= 0 ? d[j] : 0));
        r = max(r, d[i]);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
