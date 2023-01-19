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
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vi t(m);
    for (auto &s: v)cin >> s;
    for (int &x: t)cin >> x;
    int r = 0;
    for (int i = 0; i < m; i++) {
        int mm = 0;
        map<int, int> ck;
        for (int k = 0; k < n; k++) {
            mm = max(mm, ++ck[v[k][i]]);
        }
        r += mm * t[i];
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
