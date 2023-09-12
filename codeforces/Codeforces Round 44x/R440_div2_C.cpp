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
    int x;
    cin >> x;
    if (x % 4 == 0)cout << x / 4 << endl;
    else if (x % 4 == 1 && x >= 9) cout << (x - 9) / 4 + 1 << endl;
    else if (x % 4 == 2 && x >= 6)cout << (x - 6) / 4 + 1 << endl;
    else if (x % 4 == 3 && x >= 15)cout << (x - 15) / 4 + 2 << endl;
    else cout << -1 << endl;
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

