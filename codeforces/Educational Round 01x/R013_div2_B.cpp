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

bool is_leap_year(int x) {
    return x % 400 == 0 || (x % 4 == 0 && x % 100 != 0);
}

void solve() {
    int n;
    cin >> n;

    int t = is_leap_year(n);
    int c = 0;
    while (true) {
        c++;
        if (is_leap_year(n))c++;
        n++;
        c %= 7;
        if (c == 0 && t == is_leap_year(n))break;
    }

    cout << n << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
