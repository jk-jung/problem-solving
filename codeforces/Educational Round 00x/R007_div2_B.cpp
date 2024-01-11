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
    int a = (s[0] - '0') * 10 + s[1] - '0';
    int b = (s[3] - '0') * 10 + s[4] - '0';
    int t;
    cin >> t;
    b += t;
    if (b >= 60) {
        a += b / 60;
        b %= 60;
    }
    if (a >= 24) a %= 24;
    printf("%02d:%02d", a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
