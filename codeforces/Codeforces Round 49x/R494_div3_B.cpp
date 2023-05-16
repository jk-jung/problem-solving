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
    int a, b, c;
    cin >> a >> b >> c;
    int d = 0;
    if (a < b)swap(a, b), d = 1;
    string s = "0";
    a--;
    for (int i = 1; i <= c; i++) {
        if (i % 2)s += '1', b--;
        else s += '0', a--;
    }
    s = string(a + 1, '0') + string(b + 1, '1') + s.substr(2);
    for (char x: s) {
        if (d)cout << (x == '0' ? '1' : '0');
        else cout << x;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
