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

int a[2][100005];

void solve() {
    int n, q;
    cin >> n >> q;

    int st = 0;
    while (q--) {
        int y, x;
        cin >> y >> x;
        y --;
        a[y][x] ^= 1;


        int c = 0;
        for (int i = -1; i <= 1; i++) {
            int z = x + i;
            if (1 <= z && z <= n && a[y ^ 1][z]) c++;
        }
        if (a[y][x]) st += c;
        else st -= c;
        cout << (st == 0 ? "YES" : "NO") << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
