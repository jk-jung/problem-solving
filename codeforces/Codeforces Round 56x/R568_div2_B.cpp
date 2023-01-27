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

    a += ' ';
    for (int i = 0, j = 0; i < a.size(); i++) {
        if (a[i] != b[j]) {
            while (i && j < b.size() && a[i - 1] == b[j])j++;
            if (a[i] == ' ' && j == b.size()) {
                cout << "YES\n";
                return;
            }
            if (j == b.size() || b[j] != a[i]) {
                cout << "NO\n";
                return;
            }
        }
        j++;
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
