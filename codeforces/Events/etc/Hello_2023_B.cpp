#include <cstring>
#include <cstdio>
#include <cmath>
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
    if (n == 3)cout << "NO\n";
    else if (n % 2 == 0) {
        cout << "YES\n";
        for (int i = 0; i < n; i++)cout << 1 * (i % 2 ? -1 : 1) << " ";
        cout << endl;
    } else {
        cout << "YES\n";
        int x = n / 2;
        for (int i = 0; i < n; i++)cout << (i % 2 ? -x : x - 1) << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
