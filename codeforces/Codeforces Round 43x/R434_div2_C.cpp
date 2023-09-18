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

    string r, m = "aeiou";
    char x = 'a', y = 'a';
    for (char z: s) {
        bool flag = false;
        if (m.find(x) == -1 && m.find(y) == -1 && m.find(z) == -1 && !(x == y && y == z)) {
            r += ' ';
            flag = true;
        }
        r += z;
        x = y;
        y = z;
        if (flag)x = 'a';
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
