/*
 * Idea
 * - 첫 두 쿼리에서 중요한 정보를 모두 알아낼 수 있다.
 */

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


int q(string s) {
    cout << s << endl;
    int x;
    cin >> x;
    if (x == 0)exit(0);
    return x;
}

void solve() {
    int na = 300 - q(string(300, 'a'));
    int nb = 300 - q(string(300, 'b'));

    if(na == 0)q(string(nb, 'b'));
    else if(nb == 0)q(string(na, 'a'));
    else {
        int n = na + nb;
        string s = string(n, 'a');
        int num_b = nb;
        int best = num_b;
        for (int i = 0; i < n - 1; i++) {
            s[i] = 'b';
            int x = q(s);
            if (x >= best)s[i] = 'a';
            else best = x;
        }
        for (int i = 0; i < n; i++)if (s[i] == 'b')num_b--;
        if (num_b)s[n - 1] = 'b';
        q(s);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
