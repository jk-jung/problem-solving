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
    int n;
    cin >> n;
    if (n % 2 == 0)
        cout << (n - 1) / 2 << " " << n / 2 << " " << 1 << endl;
    else {
        int m = n / 2;
        if (m % 2) m -= 2;
        else m -= 1;
        cout << m << " " << n - 1 - m << " " << 1 << endl;
    }
    // 1 +
    // 홀 +  홀 + 홀
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
