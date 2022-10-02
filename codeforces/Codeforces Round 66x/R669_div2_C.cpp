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

int q(int x, int y) {
    cout << "? " << x + 1<< " " << y + 1<< endl;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "! 1" << endl;
        return;
    }
    vi r(n);
    int idx = 0;
    for (int i = 1; i < n; i++) {
        int a = q(idx, i);
        int b = q(i, idx);
        if (a > b) {
            r[idx] = a;
            idx = i;
        } else {
            r[i] = b;
        }
    }
    r[idx] = n;

    cout << "! ";
    for (int x: r)cout << x << " ";;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
