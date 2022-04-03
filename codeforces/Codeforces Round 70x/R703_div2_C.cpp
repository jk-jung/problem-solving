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

map<pi, int> ck;
int CNT = 0;

int q(int l, int r) {
    if (l > r)swap(l, r);
    pi k = {l, r};
    if(ck.count(k)) return ck[k];
    assert(l != r);
    assert(CNT < 20);
    cout << "? " << l << " " << r << endl;
    cin >> l;
    CNT ++;
    return ck[k] = l;
}

void solve() {
    int n;
    cin >> n;

    int idx = q(1, n), s, e, r = -1, ck = 0;
    if (idx == 1 || (idx != n && q(idx, n) == idx)) {
        ck = 1;
        s = idx;
        e = n;
        r = idx + 1;
    } else {
        s = 1;
        e = idx;
        r = idx - 1;
    }
    while (s <= e) {
        int m = (s + e) / 2;
        if (idx != m && q(idx, m) == idx) {
            r = m;
            if (ck) e = m - 1;
            else s = m + 1;
        } else {
            if (ck) s = m + 1;
            else e = m - 1;
        }
    }
    cout << "! " << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
