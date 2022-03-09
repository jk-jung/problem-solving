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


bool ck(int k1, int k2, int cnt) {
    if (k1 > k2)swap(k1, k2);
    return k1 + (k2 - k1) / 2 >= cnt;
}

void solve() {
    int n, k1, k2;
    int w, b;
    cin >> n >> k1 >> k2 >> w >> b;
    int r = ck(k1, k2, w) && ck(n - k1, n - k2, b);
    cout << (r ? "YES\n" : "NO\n");

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
