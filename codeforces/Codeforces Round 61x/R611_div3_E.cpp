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

int find_max(vi &v) {
    vi ck(n + 2);
    int r = 0;
    for (int x: v) {
        for (int i = -1; i <= 1; i++) {
            if (!ck[x + i]) {
                ck[x + i] = 1;
                r++;
                break;
            }
        }
    }
    return r;
}

int find_min(vi &v) {
    vi ck(n + 2);
    int r = 0;
    for (int x: v) {
        bool ok = false;
        for (int i = -1; i <= 1; i++) {
            if (ck[x + i]) ok = true;
        }
        if (ok)continue;

        for (int i = 1; i >=-1; i--) {
            if (!ck[x + i]) {
                ck[x + i] = 1;
                r++;
                break;
            }
        }
    }
    return r;
}

void solve() {
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());

    cout << find_min(v) << " " << find_max(v) << " " << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
