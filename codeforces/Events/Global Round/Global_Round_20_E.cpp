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

int q(int x) {
    cout << "? " << x << endl;
    cin >> x;
    return x;
}

void solve() {
    cin >> n;
    int s = 1 * n + n - 1, e = 2000 * n + n - 1, tot = -1;
    while (s <= e) {
        int m = (s + e) / 2;
        if (q(m) == 1)tot = m, e = m - 1;
        else s = m + 1;
    }

    int r = tot;
    set<int> candi;
    for (int h = 2; h <= n; h++) {
        for (int k = 0; k < h - 1; k++) {
            int need = tot - h + 1 + k;
            if(need % h) continue;
            candi.insert(need / h);
        }
    }
    for(int w: candi) {
        int h = q(w);
        if(h) r = min(r, w * h);
    }
    cout << "! " << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
