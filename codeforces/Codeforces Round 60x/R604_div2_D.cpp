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

int r[100005];
int n;


// 0 1
// 1 0 2
// 2 1 3
// 3 2

vi nt[4] = {
    {1},
    {0, 2},
    {1, 3},
    {2},
};

bool check(int x, vi v) {
    if (v[x] == 0)return false;
    for (int i = 0; i < n; i++) {
        r[i] = x;
        v[x] --;

        if(i + 1 < n) {
            int nxt = -1;
            for (int y: nt[x]) {
                if (v[y]) {
                    nxt = y;
                    break;
                }
            }
            if (nxt == -1)return false;
            x = nxt;
        }
    }
    return true;
}

void solve() {
    vi v(4);
    for (int &x: v)cin >> x;
    n = v[0] + v[1] + v[2] + v[3];

    for (int i = 0; i < 4; i++) {
        if (check(i, v)) {
            cout << "YES\n";
            for (int i = 0; i < n; i++)cout << r[i] << " ";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
