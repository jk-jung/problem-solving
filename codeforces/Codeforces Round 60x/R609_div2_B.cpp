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

void read(map<int, int> &a) {
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a[x]++;
    }
}

void solve() {
    cin >> n >> m;
    map<int, int> a, b;
    read(a), read(b);

    int r = m;
    for (auto [y, i]: b) {
        int x = a.begin()->F;
        int need = (y - x + m) % m;

        bool ok = true;
        for (auto [z, j]: a) {
            int q = (z + need) % m;
            if (!b.count(q) || b[q] != j) {
                ok = false;
                break;
            }
        }
        if (ok)
            r = min(r, need);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
