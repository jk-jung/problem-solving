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
    for (auto &s: v)cin >> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '.') v[i][j] = 'D';
        }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i && v[i][j] == 'W' && v[i - 1][j] == 'S')ok = false;
            if (j && v[i][j] == 'W' && v[i][j - 1] == 'S')ok = false;
            if (i && v[i][j] == 'S' && v[i - 1][j] == 'W')ok = false;
            if (j && v[i][j] == 'S' && v[i][j - 1] == 'W')ok = false;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
    if(ok)
        for(const auto& x:v)cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
