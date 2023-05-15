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
    map<int, int> c;
    for (int &x: v)cin >> x, c[x]++;
    int r = 0;
    for (int x: v) {
        bool ok = false;
        for (int i = 1; i <= 30; i++) {
            int y = (1 << i) - x;
            if (x == y) {
                if (c[x] >= 2)ok = true;
            } else if (y > 0 && c.count(y))ok = true;
        }
        if (!ok) r++;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
