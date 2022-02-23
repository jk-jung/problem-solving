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
    for (int i = 0; i < n; i++)v[i] = n-i;

    int m = 0;
    while (m < n) {
        bool ok = true;
        for (int i = 0; i < n - 2; i++) {
            if (v[i] + v[i + 1] == v[i + 2]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            m ++;
            for(int &x: v)cout << x <<" " ;
            cout << '\n';
        }
        prev_permutation(v.begin(), v.end());
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
