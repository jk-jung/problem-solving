#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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


int solve2(int a, int b) {
    int r = 0;
    for (int i = 30; i >= 0; i--) {
        int aa = a >> i & 1;
        int bb = b >> i & 1;
        int nn = 1 << i;
        int all = (1 << (i + 1)) - 1;

        if (aa == 1) {
            if (b == all)
                return r + b + 1;
            else if (a > b)
                return r;
            else {
                b++;
                for (int j = i; j >= 0; j--) {
                    aa = a >> j & 1;
                    bb = b >> j & 1;

                    if (aa == 0 && bb == 1) {
                        r |= (1 << j);
                        a += (1 << j);
                    }

                    if (a >= b) return r;
                }
                return r + 1;
            }

        }
        r += bb * nn;
        b -= bb * nn;
    }
    return r + 1;
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << solve2(a, b) << endl;
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
