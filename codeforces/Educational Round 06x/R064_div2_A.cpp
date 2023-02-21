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
    int n;
    cin >> n;
    vi v(n);
    int r = 0;
    for (int &x: v)cin >> x;
    int z = -1;
    for (int i = 1; i < n; i++) {
        int x = v[i - 1];
        int y = v[i];
        if (x == 1 && y == 2)r += 3;
        if (x == 1 && y == 3)r += 4;
        if (x == 2 && y == 1)r += 3;
        if (x == 2 && y == 3) {r = - 1; break;}
        if (x == 3 && y == 1)r += 4;
        if (x == 3 && y == 2) {r = - 1; break;}
        if (z == 3 && x == 1 && y == 2) r --;
        z = x;
    }
    if(r == -1)cout << "Infinite\n";
    else cout <<"Finite\n" << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
