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
    int n;
    cin >> n;
    if (n % 2) {
        cout << (n == 1 ? "FastestFinger\n" : "Ashishgup\n");
    } else {
        int c = 0;
        while (n % 2 == 0)n /= 2, c++;
        int t = 0;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                t = 1;
                break;
            }
        }
        if (c == 1) {
            cout << (n == 1 ||  t == 1 ? "Ashishgup\n" : "FastestFinger\n");
        } else {
            cout << (n == 1 ? "FastestFinger\n" : "Ashishgup\n");
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
