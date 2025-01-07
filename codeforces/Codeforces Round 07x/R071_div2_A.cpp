#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))


void solve() {
    int x, y;
    cin >> x >> y;
    for (int i = 0;; i++) {
        int cur = 22;
        if (i % 2 == 0) {
            if (x > 0)cur -= 10, x--;
            if (x > 0)cur -= 10, x--;
            y -= cur;
        } else {
            y -= 2;
            if (y >= 10)cur -= 10, y -= 10;
            else cur -= 10, x--;
            if (y >= 10)cur -= 10, y -= 10;
            else cur -= 10, x--;
        }

        if (y < 0 || x < 0) {
            cout << (i % 2 ? "Ciel" : "Hanako");
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
