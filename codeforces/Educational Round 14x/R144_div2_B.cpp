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
    string a, b;
    cin >> a >> b;
    if (a[0] == b[0]) {
        cout << "YES\n" << a[0] << "*" << endl;
    } else if (a.back() == b.back()) {
        cout << "YES\n" << "*" << a.back() << endl;
    } else {
        for (int i = 1; i < a.size(); i++) {
            string t = a.substr(i - 1, 2);
            if (b.find(t) != -1) {
                cout << "YES\n" << "*" << t << "*" << endl;
                return;
            }
        }
        cout << "NO\n" << endl;
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
