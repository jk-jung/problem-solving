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

int r[3];

int q(int a, int b, int c) {
    cout << "? " << a << " " << b << " " << c << endl;
    int t;
    cin >> t;
    return t;
}

void solve() {
    int n;
    cin >> n;

    r[0] = 1;
    r[1] = 2;
    r[2] = 3;
    int dif = q(1, 2, 3);

    for (int i = 4; i <= n; i++) {
        int v = q(r[0], r[1], i);
        int v2 = q(r[0], r[2], i);

        if(v2 > dif || v > dif) {
            if (v2 > v) {
                r[1] = i;
                dif = v2;
            } else {
                r[2] = i;
                dif = v;
            }
        }
    }
    int t = -1;
    for (int i = 1; i <= n; i++) {
        if (i == r[0])continue;
        if (i == r[1])continue;
        if (i == r[2])continue;
        t = i;
        break;
    }

    int v1 = q(r[0], r[1], t);
    int v2 = q(r[0], r[2], t);

    if(v1 == dif) ;
    else if(v2 == dif) r[1] = r[2];
    else {
        r[0] = r[1];
        r[1] = r[2];
    }
    cout << "! " << r[0] << " " << r[1] << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
