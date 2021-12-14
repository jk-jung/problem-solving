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

bool ck[1000005];
vi p;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)cout << p[i] << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 2; i <= 1000000; i++) {
        if (ck[i])continue;
        p.pb(i);
        for (int j = i + i; j <= 1000000; j += i)ck[j] = 1;
    }

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
