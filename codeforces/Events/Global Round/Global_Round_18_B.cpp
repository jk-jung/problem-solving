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

int N = 200000;
int ss[22][200005];

void solve() {
    int s, e;
    cin >> s >> e;
    int r = 1 << 30;
    for (int k = 0; k < 20; k++) {
        int c = ss[k][e] - ss[k][s - 1];
        r = min(r, e - s + 1 - c);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int k = 0; k < 20; k++) {
        for (int i = 1; i <= N; i++)
            ss[k][i] += (i >> k & 1) + ss[k][i - 1];
    }

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
