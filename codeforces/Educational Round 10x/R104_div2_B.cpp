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
    int n, k;
    cin >> n >> k;

    k--;
    if (n % 2 == 0) {
        cout << k % n + 1 << endl;
    } else {
        int mid = n / 2;
        int cy = k / n % mid;
        int p1 = mid - cy;
        int p2 = n - 1 - cy;

        k %= n;
        if(k >= p2)k += 2;
        else if(k >= p1)k += 1;
        k += cy * 2;
        cout << k % n + 1 << endl;
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
