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
    int s = 0;
    vi v(4);
    for (int &x: v)cin >> x, s += x;
    for (int i = 0; i < (1 << 4); i++) {
        int k = 0;
        for (int x = 0; x < 4; x++)if (i >> x & 1)k += v[x];
        if (k * 2 == s) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
