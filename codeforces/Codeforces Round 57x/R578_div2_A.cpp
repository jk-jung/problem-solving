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
    string r = string(10, '0');
    string s;
    int n;
    cin >> n >> s;
    for (char x: s) {
        if (x == 'L') {
            for (int i = 0; i < 10; i++)
                if (r[i] == '0') {
                    r[i] = '1';
                    break;
                }
        } else if (x == 'R') {
            for (int i = 9; i >= 0; i--)
                if (r[i] == '0') {
                    r[i] = '1';
                    break;
                }
        } else {
            r[x - '0'] = '0';
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
