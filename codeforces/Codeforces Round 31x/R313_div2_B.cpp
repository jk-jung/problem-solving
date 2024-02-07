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

bool f(int n, int m, int a, int b, int c, int d) {
    return a + c <= n && max(b, d) <= m;
}

void solve() {
    int n, m;
    int a, b, c, d;
    cin >> n >> m >> a >> b >> c >> d;
    bool r = false;
    r |= f(n, m, a, b, c, d);
    r |= f(n, m, a, b, d, c);
    r |= f(n, m, b, a, c, d);
    r |= f(n, m, b, a, d, c);
    r |= f(m, n, a, b, c, d);
    r |= f(m, n, a, b, d, c);
    r |= f(m, n, b, a, c, d);
    r |= f(m, n, b, a, d, c);

    cout << (r ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
