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
    string s;
    cin >> s;
    vi v;
    v.pb(0);
    for (char x: s) {
        if (x == 'a') {
            v.back()++;
        } else if (x == 'b' && v.back() > 0)v.pb(0);
    }
    ll r = 1;
    for (int x: v) {
        r = (r * (x + 1)) % 1000000007;
    }
    cout << (r - 1 + 1000000007) % 1000000007 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
