#include <cstring>
#include <cstdio>
#include <cmath>
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
string s;
int d[100005][3][3];

int go(int idx, int state, int last) {
    if(idx == n)return 0;
    int &r = d[idx][state][last];
    if (r != -1) return r;

    int x = s[idx] - '0';
    int y = x ^ 1;
    if (state == 0) {
        r = max(
            go(idx + 1, 0, x) + (x != last),
            go(idx + 1, 1, y) + (y != last)
        );
    } else if (state == 1) {
        r = max(
            go(idx + 1, 2, x) + (x != last),
            go(idx + 1, 1, y) + (y != last)
        );
    } else {
        r = go(idx + 1, 2, x) + (x != last);
    }

    return r;
}

void solve() {
    memset(d, -1, sizeof(d));
    cin >> n >> s;

    cout << go(0, 0, 2) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
