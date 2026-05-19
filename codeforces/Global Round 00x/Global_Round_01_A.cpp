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
    int b, k;
    cin >> b >> k;
    vi v(k);
    for (int &x: v)cin >> x;
    reverse(v.begin(), v.end());
    int r = 0, t = 1;
    for (int x: v) {
        r = (r + x * t) % 2;
        t = (t * b) % 2;
    }
    cout << (r ? "odd" : "even") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
