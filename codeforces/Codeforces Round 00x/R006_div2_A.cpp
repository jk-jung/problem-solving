#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))


void solve() {
    vi v(4);
    for (int &x: v)cin >> x;
    bool a = false, b = false;
    for (int i = 0; i < 4; i++) {
        vi t;
        for (int j = 0; j < 4; j++) {
            if (i != j)t.pb(v[j]);
        }
        sort(t.begin(), t.end());
        if (t[0] + t[1] > t[2])a = true;
        if (t[0] + t[1] == t[2])b = true;
    };
    if (a)cout << "TRIANGLE\n";
    else if (b)cout << "SEGMENT\n";
    else cout << "IMPOSSIBLE\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
