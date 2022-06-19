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

int n;

bool can(string &s, int x) {
    int last = 0;
    for (int i = 1; i < n; i++) {
        if (last + x < i) break;
        if (s[i] == 'R')last = i;
        if (last + x >= n)return true;
    }
    return false;
}

void solve() {
    string v;
    cin >> v;
    n = v.size();
    n++;
    v = 'R' + v;

    int s = 1, e = n, r = -1;
    while (s <= e) {
        int m = (s + e) / 2;
        if (can(v, m))e = m - 1, r = m;
        else s = m + 1;
    }
    cout << r << endl;
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
