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

int mex[300005];

void solve() {
    int a, b, r;
    cin >> a >> b;

    if (mex[a - 1] == b) {
        r = a;
    } else if ((mex[a - 1] ^ b) == a) {
        r = a + 2;
    } else {
        r = a + 1;
    }

    cout << r << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 300000; i++)mex[i] = mex[i - 1] ^ i;

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
