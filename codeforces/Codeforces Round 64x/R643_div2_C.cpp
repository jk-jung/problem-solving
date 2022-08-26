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
    int A, B, C, D;
    cin >> A >> B >> C >> D;


    ll r = 0;
    for (int z = C, i = 1; z <= D; z++, i++) {
        int sy = max(z / 2 + 1, B);
        if (sy > C)continue;

        int len_y = C - sy + 1;
        int all = max(0, A - i + 1);
        ll c1 = min(len_y, all);
        r += c1 * (B - A + 1);
        ll c2 = len_y - c1;
        ll a = max(A, i - 1);
        ll c3 = B - a;
        ll m = max(0ll, min(c2, c3));
        r += (B - a + 1) * m - m * (m + 1) / 2;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}