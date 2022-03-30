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
    int n;
    cin >> n;
    vi v(3);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[x % 3]++;
    }
    int m = n / 3;

    int r = 0;
    for (int i = 0; i < 10; i++) {
        int k = i % 3;
        if (v[k] > m) {
            int t = v[k] - m;
            r += t;
            v[k] = m;
            v[(k + 1) % 3] += t;
        }
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
