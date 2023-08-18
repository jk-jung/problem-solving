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
    int n, pos, l, r;
    cin >> n >> pos >> l >> r;

    if (l == 1 && r == n) cout << 0;
    else if (l == 1) cout << ab(r - pos) + 1;
    else if (r == n) cout << ab(pos - l) + 1;
    else {
        int t = min(ab(pos - l), ab(pos - r)) + r - l + 2;
        cout << t;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
