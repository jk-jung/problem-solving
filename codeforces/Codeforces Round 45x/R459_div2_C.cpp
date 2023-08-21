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
    int r = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i, y = 0, used = 0, unused = 0; j < s.size(); j++) {
            if (s[j] == '?') {
                if (y > 0) used++, y--;
                else unused++;
            } else if (s[j] == '(') {
                y++;
            } else {
                if (y > 0)y--;
                else if (used) {
                    used--;
                    unused++;
                } else if (unused) {
                    unused--;
                } else {
                    break;
                }
            }
            if (y == 0 && unused % 2 == 0)r++;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
