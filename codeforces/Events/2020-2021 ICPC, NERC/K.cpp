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

bool ok(vi &v) {
    for (int i = 0; i < v.size(); i++)if (i != v[i]) return false;
    return true;
}

void op1(vi &v) {
    for (int i = 0; i < v.size(); i += 2)swap(v[i], v[i + 1]);
}

void op2(vi &v) {
    int n = v.size() / 2;
    for (int i = 0; i < n; i++)swap(v[i], v[i + n]);
}

int calc(vi v) {
    int r = 0;
    for (int i = 0; i < v.size(); i++) {
        if (ok(v)) break;
        op2(v), r++;
        if (ok(v)) break;
        op1(v), r++;
        if(i == v.size() - 1) return 1 << 30;
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    vi v(n * 2);
    for (int &x: v)cin >> x, x--;

    int r = calc(v);
    op1(v);
    r = min(r, calc(v) + 1);
    if(r == (1<< 30))r = -1;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
