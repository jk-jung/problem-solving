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

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    vi A(k), B(k), ca(a + 1), cb(b + 1);
    for (int &x: A)cin >> x, ca[x]++;
    for (int &x: B)cin >> x, cb[x]++;

    int n = k;
    ll r = 0;
    for (int i = 0; i < n; i++) {
        ca[A[i]] --;
        cb[B[i]] --;
        k --;
        r += k - ca[A[i]] - cb[B[i]];

    }
    cout << r << endl;
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
