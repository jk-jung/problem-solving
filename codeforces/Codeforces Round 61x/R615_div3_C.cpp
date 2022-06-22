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
    int n, m;
    cin >> n;
    m = n;
    map<int, int> ck;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ck[i]++;
            n /= i;
        }
    }
    if (n > 1)ck[n] = 1;
    if (ck.size() == 1) {
        int a = ck.begin()->F;
        if (ck.begin()->S >= 6) {
            cout << "YES\n" << a << " " << a * a << " " << m / a / a / a << '\n';
        } else cout << "NO\n";
    } else if (ck.size() >= 2) {
        auto it = ck.begin();
        int a = it->F;
        it++;
        int b = it->F;
        int c = m / a / b;
        if (c != a && c != b && c > 1) {
            cout << "YES\n" << a << " " << b << " " << c << '\n';
        } else cout << "NO\n";
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
