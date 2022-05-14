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


string s;
int r;

pi dfs(int x, vector<vi> &v) {
    pi t;
    if (s[x] == 'W')t.F++;
    else t.S++;

    for (int y: v[x]) {
        auto k = dfs(y, v);
        t.F += k.F;
        t.S += k.S;
    }
    if(t.F == t.S)r++;
    return t;
}

void solve() {
    int n;
    cin >> n;
    vector<vi> v(n);

    for (int i = 1, x; i < n; i++) {
        cin >> x;
        v[x - 1].pb(i);
    }
    cin >> s;
    r = 0;
    dfs(0, v);
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
