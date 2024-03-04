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
    int n, x, y;
    cin >> n >> x >> y;
    set<pi> s;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a = a - x;
        b = b - y;
        int g = gcd(a, b);
        a /= g;
        b /= g;
        if(b < 0) a = -a, b = -b;
        if(b == 0)a = 0;
        s.insert(mp(a, b));
    }
    cout << s.size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
