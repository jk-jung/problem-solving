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

bool f(char x) {
    if (x == 'a') return true;
    if (x == 'e') return true;
    if (x == 'i') return true;
    if (x == 'o') return true;
    if (x == 'u') return true;
    if (x == 'n') return true;
    return false;
}

void solve() {
    string s;
    cin >> s;
    char x = s[0];
    for (int i = 1; i < s.size(); i++) {
        char y = s[i];
        if (!f(x) && (!f(y) || y == 'n')) {
            cout << "NO\n";
            return;
        }
        x = y;
    }
    if (!f(x)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
