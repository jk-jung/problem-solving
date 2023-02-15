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

void print(vi &a) {
    cout << a.size() << endl;
    for (int x: a)cout << x << " ";
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    map<int, int> ck;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (++ck[x] == 3) {
            cout << "NO\n";
            return;
        }
    }

    vi a, b;
    for (auto [x, y]: ck) {
        if (y)a.pb(x), y--;
        if (y)b.pb(x), y--;
    }
    reverse(b.begin(), b.end());
    cout << "YES\n";
    print(a);
    print(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}