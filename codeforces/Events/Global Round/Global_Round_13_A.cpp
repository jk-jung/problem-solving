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

void solve() {
    int n, q;
    cin >> n >> q;
    vi v(n);
    int one = 0;
    for (int &x: v)cin >> x, one += x == 1;
    while (q--) {
        int a, b;
        cin >> a >> b;

        if (a == 1) {
            if (v[b - 1] == 1)one--;
            else one++;
            v[b - 1] = 1 - v[b - 1];
        } else {
            cout << (b <= one ? 1 : 0) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
