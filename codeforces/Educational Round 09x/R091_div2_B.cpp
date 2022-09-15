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
    string s;
    cin >> s;
    map<char, int> ck;
    for (char x: s)ck[x]++;
    char r = 'R';
    for (auto [x, y]: ck) {
        if (ck[r] < ck[x]) {
            r = x;
        }
    }
    if (r == 'R') r = 'P';
    else if (r == 'S') r = 'R';
    else r = 'S';
    cout << string(s.size(), r) << endl;
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
