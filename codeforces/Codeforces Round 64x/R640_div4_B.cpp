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

    if (k <= n && (n - k) % 2 == 0) {
        cout << "YES\n";
        for (int i = 0; i < k - 1; i++)cout << 1 << " ";
        cout << (n - k + 1) << endl;
        return;
    }
    if (k * 2 <= n && (n - k * 2) % 2 == 0) {
        cout << "YES\n";
        for (int i = 0; i < k - 1; i++)cout << 2 << " ";
        cout << (n - k * 2 + 2) << endl;
        return;
    }
    cout << "NO\n";
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
