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

void solve() {
    int n;
    cin >> n;
    map<int, int> ck;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        ck[x]++;
    }

    ll r = 0;
    priority_queue<int> q;
    for (int i = 0; i <= n; i++) {
        if(r == -1) cout << r << " ";
        else {
            int c = ck[i];
            cout << r + c << " ";

            while (c--)q.push(i);
            if(q.empty()) {
                r = -1;
            } else {
                int x = q.top();
                q.pop();
                r += (i - x);
            }
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
