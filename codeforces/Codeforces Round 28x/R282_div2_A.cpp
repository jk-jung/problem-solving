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
    int r = 1;
    for (char x: s) {
        if (x == '0') r *= 2;
        if (x == '1') r *= 7;
        if (x == '2') r *= 2;
        if (x == '3')r *= 3;
        if (x == '4')r *= 3;
        if (x == '5')r *= 4;
        if (x == '6')r *= 2;
        if (x == '7') r *= 5;
        if (x == '9') r *= 2;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
