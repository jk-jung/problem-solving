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

int n;

int g(int x, int m) {
    if(x == m && n == 1)return m - 1;
    if (x + n > m) return m;
    return x + n;
}

int f(string &s) {
    map<char, int> ck;
    int r = 0;
    for (char &x: s)++ck[x];
    for (auto &[k, v]: ck) {
        r = max(r, g(v, s.size()));
    }
    if(ck.size() < 52)r = max(r, g(0, s.size()));
    return r;
}


void solve() {
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;

    int x = f(a);
    int y = f(b);
    int z = f(c);

    int t = max(x, max(y, z));
    int cc = 0;
    if (x == t)cc++;
    if (y == t)cc++;
    if (z == t)cc++;
    if (cc >= 2) cout << "Draw" << endl;
    else if (x > y && x > z) cout << "Kuro" << endl;
    else if (y > x && y > z) cout << "Shiro" << endl;
    else cout << "Katie" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
