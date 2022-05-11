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

vector<vi> ord = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 0, 2},
        {1, 2, 0},
        {2, 0, 1},
        {2, 1, 0},
};

void solve() {
    int n;
    vi a(3), b(3);
    cin >> n;
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;

    int r = 1 << 30;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++) {
            vi &o1 = ord[i];
            vi &o2 = ord[j];

            vi x = a, y = b;
            int p=0, q = 0, tt =0;
            while(p < 3 && q < 3) {
                int k1 = o1[p], k2 = o2[q];
                if(x[k1] == 0) { p++; continue; }
                if(y[k2] == 0) { q++; continue; }
                int t = min(x[k1], y[k2]);
                x[k1] -= t;
                y[k2] -= t;
                if ((k1 + 1) % 3 == k2) tt += t;
            }
            r = min(r, tt);
        }

    int rr = 0;
    for (int i = 0; i < 3; i++) {
        rr += min(a[i], b[(i + 1) % 3]);
    }

    cout << r << " " << rr << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
