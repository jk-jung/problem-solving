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
    vi v(n);
    for (int &x: v)cin >> x;
    vi t;
    for (int i = 1; i < n - 1; i++) {
        if (v[i - 1] == 1 && v[i + 1] == 1 && v[i] == 0)t.pb(i);
    }
    int r = 0;
    for (int i = 0; i < t.size(); i++) {
        r++;
        if (i && t[i - 1] + 2 == t[i]) {
            r--;
            t[i] = -1000;
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
