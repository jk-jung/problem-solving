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
    map<char, int> ck;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ck[s[0]]++;
    }
    int r = 0;
    for (auto [x, y]: ck) {
        int a = y / 2, b = (y + 1) / 2;
        r += (a * (a - 1)) / 2 + (b * (b - 1) / 2);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
