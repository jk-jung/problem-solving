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
    int a, b, f, k;
    cin >> a >> b >> f >> k;

    int c = b, r = 0;
    for (int i = 0; i < k; i++) {
        int nf = i % 2 == 0 ? f : a - f;
        if (c < nf) {
            cout << "-1\n";
            return;
        }
        c -= nf;
        int nxt = a - nf;
        if (i != k - 1) nxt *= 2;
        if (c < nxt) {
            c = b;
            r++;
            if (c < nxt) {
                cout << "-1\n";
                return;
            }
        }
        c -= a - nf;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
