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

char v[10][10];

void solve() {
    for (int i = 0; i < 8; i++) cin >> v[i];
    int a = 1 << 30, b = 1 << 30;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (v[i][j] == 'W') {
                bool ok = true;
                for (int k = i - 1; k >= 0; k--)if (v[k][j] != '.')ok = false;
                if (ok) a = min(a, i);
            }
            if (v[i][j] == 'B') {
                bool ok = true;
                for (int k = i + 1; k < 8; k++)if (v[k][j] != '.')ok = false;
                if (ok) b = min(b, 7 - i);
            }
        }
    }
    if (a <= b) cout << "A" << endl;
    else cout << "B" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
