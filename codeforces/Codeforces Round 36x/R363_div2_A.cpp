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
    string s;
    cin >> n >> s;
    vi v(n);
    for (int &x: v)cin >> x;

    int r = 1 << 30;
    for (int i = 1; i < n; i++) {
        if (s[i] == 'L' && s[i - 1] == 'R') {
            r = min(r, (v[i] - v[i - 1]) / 2);
        }
    }
    cout << (r == 1 << 30 ? -1 : r) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
