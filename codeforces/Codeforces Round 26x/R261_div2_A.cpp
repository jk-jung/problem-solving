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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if(x1 == x2) {
        int d = y2 - y1;
        cout << x1 + d << " " << y1 << " " << x2 + d << " " << y2 << endl;
    } else if(y1 == y2) {
        int d = x2 - x1;
        cout << x1 << " " << y1 + d << " " << x2 << " " << y2 + d << endl;
    } else if(ab(x1 - x2) == ab(y1 - y2)) {
        cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
