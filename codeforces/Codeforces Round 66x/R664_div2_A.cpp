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

bool check(int a, int b, int c, int d) {
    if (a < 0 || b < 0 || c < 0)return false;
    int t = a % 2 + b % 2 + c % 2 + d % 2;
    return t <= 1;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (check(a, b, c, d) || check(a - 1, b - 1, c - 1, d + 3)) {
        cout << "Yes\n";
    } else cout << "No\n";
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
