#include <string.h>
#include <stdio.h>
#include <math.h>
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

string s;

int can(int x) {
    if(x == 0 && (s == "0" || s == "_" || s == "X")) return 1;
    int i = 0, X = -1;
    while (x) {
        if (i == s.size()) return 0;
        int a = x % 10;
        int b = s[i] - '0';
        x /= 10;

        if (s[i] == 'X' && X == -1) X = a;
        else if(s[i] == 'X' && X != a) return 0;
        else if(0 <= b && b<= 9 && a != b) return 0;
        i++;
    }
    return i == s.size();
}

void solve() {
    cin >> s;
    reverse(s.begin(), s.end());
    int r = 0;
    for (int i = 0; i < 1000000000; i += 25) {
        r += can(i);
    }

    cout << r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
