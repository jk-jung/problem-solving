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
    vi v = {4, 8, 15, 16, 23, 42};
    vi t(4), u(6);
    for (int i = 0; i < 4; i++) {
        cout << "? " << 1 << " " << i + 2 << endl;
        cin >> t[i];
    }


    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < 6; i++)
            for (int j = i + 1; j < 6; j++) {
                if (v[i] * v[j] == t[k]) {
                    u[i] += k + 1;
                    u[j] += k + 1;
                }
            }
    }

    vi ord = {10, 1, 2, 3, 4, 0};

    cout << "! ";
    for (int x: ord) {
        for (int i = 0; i < 6; i++)if (u[i] == x)cout << v[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
