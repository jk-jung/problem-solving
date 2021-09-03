#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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

int s1[300005];

void solve() {
    int n, q;
    string v;
    cin >> n >> q >> v;

    for (int i = 0, ck = 1; i < n; i++, ck *= -1) {
        int k = v[i] == '+' ? 1 : -1;
        s1[i + 1] = s1[i] + k * ck;
    }

    while (q--) {
        int L, R, r;
        cin >> L >> R;
        if (s1[R] - s1[L - 1] == 0) {
            r = 0;
        } else if ((R - L + 1) % 2 == 1) {
            r = 1;
        } else {
            r = 2;
        }
        cout << r << '\n';
    }

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
