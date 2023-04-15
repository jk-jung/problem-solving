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

vi r;
vi a, b;
int n;
bool ck[100005][4];

void go(int i, int x) {
    if (i == n) {
        cout << "YES\n";
        for (int x: r)cout << x << " ";
        exit(0);
    }
    if (ck[i][x]) return;
    ck[i][x] = true;
    for (int y = 0; y < 4; y++) {
        bool ok = true;
        if (i > 0) ok = (x | y) == a[i - 1] && (x & y) == b[i - 1];
        if (ok) {
            r.pb(y);
            go(i + 1, y);
            r.pop_back();
        }
    }
}


void solve() {
    cin >> n;
    a.resize(n - 1), b.resize(n - 1);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;
    go(0, 0);
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
