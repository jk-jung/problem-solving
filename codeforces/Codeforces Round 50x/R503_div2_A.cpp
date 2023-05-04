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

void solve() {
    int n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;

    while (k--) {
        int w, x, y, z;
        cin >> w >> x >> y >> z;
        int r = ab(w - y);
        if (r == 0)r += ab(x - z);
        else if (x < a && z < a) r += a - x + a - z;
        else if (x > b && z > b) r += x + z - b - b;
        else r += ab(x - z);
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
