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
    int n, h;
    cin >> n >> h;
    vi v(n);
    for (int &x: v)cin >> x;
    v.pb(0);
    vi t;
    for (int x: v) {
        t.pb(x);
        sort(t.begin(), t.end());
        int hh = h;
        for (int i = (int)t.size() - 1; i >= 0; i -= 2) {
            int k = max(t[i], i - 1 >= 0 ? t[i - 1] : 0);
            hh -= k;
            if (hh < 0)break;
        }
        if (hh < 0)break;
    }
    cout << (int) t.size() - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
