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
    int n, m;
    cin >> n >> m;
    if (n % 2) {
        if (m < n)cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 0; i < n - 1; i++)cout << 1 << " ";
            cout << m - n + 1 << endl;
        }
    } else {
        if (m < n || m % 2)cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 0; i < n - 2; i++)cout << 1 << " ", m--;
            cout << m / 2 << " " << m / 2 << endl;
        }
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
