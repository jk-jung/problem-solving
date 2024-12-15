#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int a, b;
    scanf("%d:%d", &a, &b);
    for(int i = 0; i < 24 * 60; i++) {
        b++;
        if(b == 60) {
            b = 0;
            a++;
            if(a == 24) a = 0;
        }
        // to time string with total 4 digits
        string s = to_string(a);
        if(s.size() == 1) s = "0" + s;
        s += ":";
        string t = to_string(b);
        if(t.size() == 1) t = "0" + t;
        s += t;

        t = s;
        reverse(t.begin(), t.end());
        if(s == t) {
            printf("%02d:%02d\n", a, b);
            return;
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
