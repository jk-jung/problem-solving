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
    int n, x;
    cin >> n >> x;
    set<int> a, b;
    int r = 100;
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;

        if (a.count(y)) r = 0;
        if (b.count(y)) r = min(r, 1);
        if (a.count(y & x))r = min(r, 1);
        if (b.count(y & x))r = min(r, 2);
        a.insert(y);
        b.insert(y & x);
    }
    cout << (r == 100 ? -1 : r) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
