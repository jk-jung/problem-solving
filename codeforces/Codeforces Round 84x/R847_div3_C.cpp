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

vector<vi> t;
int n;

bool sf(int x, int y) {
    for (int i = 0; i < n; i++) {
        int i1 = -1, i2 = -1;
        for (int j = 0; j < t[i].size(); j++) {
            if (t[i][j] == x)i1 = j;
            if (t[i][j] == y)i2 = j;
        }
        if (i1 >= 0 && i2 >= 0) {
            if (i2 < i1) return false;
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> n;
    vector<vi> v(n, vi(n - 1));
    vi r(n);
    for (int i = 0; i < n; i++)r[i] = i + 1;
    for (int i = 0; i < n; i++)for (int &x: v[i])cin >> x;
    t = v;
    sort(r.begin(), r.end(), sf);
    for (int x: r)cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
