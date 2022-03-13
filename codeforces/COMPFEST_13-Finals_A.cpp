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
int n, m;

bool sf(pair<string, int> &aa, pair<string, int> &bb) {
    string &a = aa.F;
    string &b = bb.F;
    for (int i = 0; i < m; i++) {
        if (a[i] == b[i])continue;
        if (i % 2) return a[i] > b[i];
        else return a[i] < b[i];
    }
    return true;
}

void solve() {
    cin >> n >> m;
    vector<pair<string, int>> v(n);
    int i = 0;
    for (auto &x: v)cin >> x.F, x.S = ++i;
    sort(v.begin(), v.end(), sf);
    for (auto&[x, y]: v)cout << y << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
