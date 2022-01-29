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


int ck[1000005];

void solve() {
    int n;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        ck[x] = 1;
    }
    int m = 0;
    for (int i = 1; i <= 1000000; i++) {
        if (ck[i])continue;
        int g = 0;
        for (int j = i + i; j <= 1000000; j += i) {
            if(ck[j])g = gcd(j, g);
        }
        if(g == i) m ++;
    }
    cout << m << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
