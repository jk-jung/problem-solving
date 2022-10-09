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

const double p = std::acos(-1);

void solve() {
    int n;
    cin >> n;

    double a = p / 2 / n;
    double b = p / 2 - a;
    double r = 0.5 / cos(b);
    if (n % 2) {
        double x = r * sin((n + 1) / 2 * a) * 2 / sqrt(2);
        double y = r * sin(n / 2 * a) * 2 / sqrt(2);
        cout << x + y << endl;
    } else {
        cout << cos(a) * 2 * r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
