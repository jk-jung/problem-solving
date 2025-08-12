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
    int a, b, c;
    cin >> a >> b >> c;
    if (c != 1) {
        cout << "YES\n";
        cout << a << endl;
        for (int i = 0; i < a; i++)cout << "1 ";
        cout << endl;
    } else if (b == 1 || (b == 2 && a % 2)) {
        cout << "NO\n";
    } else if (a % 2 == 0) {
        cout << "YES\n";
        cout << a / 2 << endl;
        for (int i = 0; i < a / 2; i++)cout << "2 ";
        cout << endl;
    } else {
        cout << "YES\n";
        cout << (a - 3) / 2 + 1 << endl;
        cout << "3 ";
        for (int i = 0; i < (a - 3) / 2; i++)cout << "2 ";
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
