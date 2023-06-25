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

int q(int y, int x) {
    cout << "? " << y << " " << x << endl;
    cin >> x;
    return x;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int y = -1, x = -1;

    int a = q(1, 1) + 1;
    if (a > n) {
        y = q(1, a) + 1;
        x = a;
    } else if (a > m) {
        x = q(a, 1) + 1;
        y = a;
    } else {
        int b = q(a, a);
        int c = q(a, a - b);
        if(c == 0) {
            y = a;
            x = a - b;
        }else {
            y = a - b;
            x = a;
        }
    }


    cout << "! " << y << " " << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
