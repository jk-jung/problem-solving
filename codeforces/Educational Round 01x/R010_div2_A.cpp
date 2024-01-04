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
    int h1, h2;
    int a, b;
    cin >> h1 >> h2 >> a >> b;
    if (h1 + a * 8 >= h2) {
        cout << 0 << endl;
        return;
    }
    if (a <= b) {
        cout << -1 << endl;
        return;
    }
    h1 += a * 8;
    int h = h2 - h1;
    int d = (a - b) * 12;
    cout << (h + d - 1) / d << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
