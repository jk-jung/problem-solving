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
    int n, H, M;
    cin >> n >> H >> M;

    int r = 1 << 30;
    for (int i = 0, h, m; i < n; i++) {
        cin >> h >> m;
        int a = H * 60 + M;
        int b = h * 60 + m;
        if(b < a) b += 24 * 60;
        r = min(r, b - a);
    }
    cout << r / 60 <<" " << r % 60 << endl;
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
