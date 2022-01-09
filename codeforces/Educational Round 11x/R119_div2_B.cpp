#include <string.h>
#include <stdio.h>
#include <math.h>
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

ll read() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    return v[n - 1] - v[0];
}


void solve() {
    int w, h;
    cin >> w >> h;

    ll w1 = read();
    ll w2 = read();
    ll h1 = read();
    ll h2 = read();

    cout << max(max(w1, w2) * h, max(h1, h2) * w) << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
