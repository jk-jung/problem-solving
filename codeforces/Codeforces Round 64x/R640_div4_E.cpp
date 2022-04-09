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
    vi v(n), ck(n + 1);
    for (int &x: v)cin >> x;

    for (int i = 0; i < n; i++) {
        int s = v[i];
        for (int j = i + 1; j < n; j++) {
            s += v[j];
            if (s > n)break;
            ck[s] = 1;
        }
    }
    int r = 0;
    for (int x: v)if (ck[x])r++;
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
