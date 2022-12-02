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
    int a, b;
    string s;
    cin >> a >> b >> s;
    map<char, int> ck;
    for (char x: s) {
        if (x == 'U' && b > 0) b--;
        if (x == 'D' && b < 0) b++;
        if (x == 'R' && a > 0) a--;
        if (x == 'L' && a < 0) a++;
    }
    cout << (a == 0 && b == 0 ? "YES" : "NO") << endl;
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