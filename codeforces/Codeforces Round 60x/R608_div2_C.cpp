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

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vi v(4);
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        if (a > x) v[0]++;
        else if (a < x) v[1]++;
        if (b > y) v[2]++;
        else if (b < y) v[3]++;
    }
    int r = max(max(v[0], v[1]), max(v[2], v[3]));
    for (int i = 0; i < 4; i++) {
        if (v[i] == r) {
            cout << r << endl;
            if (i == 0)x++;
            else if (i == 1)x--;
            else if (i == 2)y++;
            else y--;
            cout << x << " " << y << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
