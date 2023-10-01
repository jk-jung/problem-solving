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

int f(char x) {
    if (x == '^') return 0;
    if (x == '>') return 1;
    if (x == 'v') return 2;
    return 3;
}

void solve() {
    char a, b;
    int n;
    cin >> a >> b >> n;
    a = f(a), b = f(b);
    n %= 4;
    int r = 0;
    if ((a + n) % 4 == b)r |= 1;
    if ((a - n + 4) % 4 == b)r |= 2;
    if (r == 3)cout << "undefined";
    else cout << (r == 1 ? "cw" : "ccw") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
