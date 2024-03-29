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
    string a;
    cin >> a;
    int x = (a[0] - '0') * 10 + (a[1] - '0');
    int y = (a[3] - '0') * 10 + (a[4] - '0');
    string z = "AM";
    if(x >= 12) {
        z = "PM";
        x -= 12;
    }
    if(x == 0) x = 12;
    cout << x / 10 << x % 10 << ":" << y / 10 << y % 10 << " " << z << endl;
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
