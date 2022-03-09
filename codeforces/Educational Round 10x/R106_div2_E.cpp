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
const int MOD = 998244353;

string a, b;
int d[1005][1005][3][2][2];

int go(int x, int y, int last=2, int used_x=0, int used_y=0) {
    if (x == a.size() && y == b.size()) return 1;
    int &r = d[x][y][last][used_x][used_y];
    if (r != -1)return r;
    r = used_x && used_y ? 1 : 0;

    char z = 'A';
    if (last == 2);
    else if (last == 0) z = a[x - 1];
    else z = b[y - 1];


    if (x < a.size() && z != a[x]) {
        r = (r + go(x + 1, y, 0, 1, used_y)) % MOD;
    }
    if (y < b.size() && z != b[y]) {
        r = (r + go(x, y + 1, 1, used_x, 1)) % MOD;
    }

    return r;
}

void solve() {
    cin >> a >> b;
    memset(d, -1, sizeof(d));
    int r = 0;

    go(2, 1);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            r = (r + go(i, j)) % MOD;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}