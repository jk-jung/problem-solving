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
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

int f(int x) {
    if (x <= 1) return x;
    if (x == 2) return 5;
    if (x == 5) return 2;
    if (x == 8) return 8;
    return -1;
}

int rev(int x) {
    int a = f(x % 10);
    int b = f(x / 10);
    if (a < 0 || b < 0)return 9999;
    return a * 10 + b;
}

void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    int a = stoi(s.substr(0, 2));
    int b = stoi(s.substr(3));


    while (true) {
        int a1 = rev(a);
        int b1 = rev(b);

        if (a1 < m && b1 < n) {
            cout << setfill('0') << setw(2) << a << ":" << setfill('0') << setw(2) << b << endl;
            return;
        }

        b++;
        if (b == m) b = 0, a++;
        if (a == n) a = 0;
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
