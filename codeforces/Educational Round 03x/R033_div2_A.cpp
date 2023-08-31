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

    for (int &x: v)cin >> x;
    vi t;
    t.pb(1);
    t.pb(2);
    t.pb(3);
    for (int x: v) {
        if (t[0] != x && t[1] != x) {
            cout << "NO\n";
            return;
        }
        if (t[0] == x)swap(t[1], t[2]);
        else swap(t[0], t[2]);
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
