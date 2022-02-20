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
    vi v(n);
    for (int &x: v)cin >> x;
    int r = n - 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = (v[j] - v[i]);
            int y = (j - i);
            int g = gcd(x, y);
            x /= g, y /= g;

            int c = 2, z = v[j];
            for (int k = j + y; k < n; k += y) {
                z += x;
                if (v[k] == z) c++;
            }
            z = v[j];
            for (int k = j - y; k >=0; k -= y) {
                z -= x;
                if(i == k)continue;
                if (v[k] == z) c++;
            }
            r = min(r, n - c);
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
