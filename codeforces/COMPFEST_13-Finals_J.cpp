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

map<int, int> ck[1005];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            if (x == 1)ck[j][i] = 1;
            if (x == 3)ck[j][i] = -1;
        }

    while (k--) {
        int x, y = 0;
        cin >> x;
        x--;

        while (true) {
            auto it = ck[x].lower_bound(y);
            if (it == ck[x].end()) break;
            int bx = x;
            x += it->S;
            y = it->F;
            ck[bx].erase(it);
        }
        cout << x + 1 << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
