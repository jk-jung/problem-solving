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
    vi a(n), b(n);
    for (int &x: a){cin >> x; while(x % 2 == 0) x /= 2;}
    for (int &x: b){cin >> x; while(x % 2 == 0) x /= 2;}

    sort(a.begin(), a.end()), reverse(a.begin(), a.end());

    priority_queue<int> q;
    for (int x: b)q.push(x);
    for (int x: a) {
        while(true) {
            int y = q.top();
            q.pop();
            if(y < x) {
                cout <<"NO\n";
                return;
            }
            if(x == y) break;
            y /= 2;
            while(y % 2 == 0)y /= 2;
            q.push(y);
        }
    }
    cout <<"YES\n";
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
