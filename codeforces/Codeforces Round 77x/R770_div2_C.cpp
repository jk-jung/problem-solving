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

    if (k == 1) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++)cout << i << '\n';
        return;
    }
    if (n % 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int a[2] = {1, 2};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout<< a[i%2] << " ";
            a[i%2] += 2;
        }

        cout << '\n';
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
