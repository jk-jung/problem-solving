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
    vi cnt(100005);
    map<int, int> ck;
    for (int &x: v)cin >> x, ck[x]++, cnt[x]++;
    int r = 0;
    for (int i = 2; i <= 200000; i++) {
        int tot = 0;
        for (auto [x, y]: ck) {
            int z = i - x;
            if (z == x)tot += y / 2;
            else if (x < z && z <= 100000) tot += min(cnt[z], y);
        }
        r = max(r, tot);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
