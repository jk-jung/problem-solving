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
    int a, b;
    cin >> a >> b;
    while (a % b) {
        if (b % 2 == 0 && b < a)b = b / 2 * 3;
        else break;
    }
    if (a < b || a % b) cout << "NO\n";
    else {
        int t = a / b;
        while (t % 3 == 0) t /= 3;
        cout << (t == 1 ? "YES" : "NO") << endl;
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
