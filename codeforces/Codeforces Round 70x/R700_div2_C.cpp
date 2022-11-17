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

int q(int x) {
    cout << "? " << x + 1 << endl;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;

    int s = 0, e = n - 2, r = 1;
    while (s <= e) {
        int m = (s + e) / 2;
        int a = q(m);
        int b = q(m + 1);
        if (a > b) {
            s = m + 1;
            r = m + 2;
        } else {
            e = m - 1;
            r = m + 1;
        }
    }
    cout << "! " << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
