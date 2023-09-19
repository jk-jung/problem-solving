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
    int r, d;
    cin >> r >> d;
    int n;
    cin >> n;
    int t = 0;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z > d)continue;
        double c = sqrt(x * x + y * y);
        if (c + z <= r && c - z >= r - d)t++;
    }
    cout << t << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
