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
    string s;
    cin >> n >> s;
    int t = 0, m = 0;

    for (char x: s)if (x == 'M') m++;
    if (m * 3 != n) {
        cout << "NO\n";
        return;
    }
    vi used(n);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if(s[i] == 'T')q.push(i);
        else {
            if(q.empty()){
                cout << "NO\n";
                return;
            }
            used[q.front()] = 1;
            q.pop();
        }
    }
    while(!q.empty())q.pop();
    for (int i = n-1; i >=0; i--) {
        if(s[i] == 'T'){
            if(!used[i])q.push(i);
        }
        else {
            if(q.empty()){
                cout << "NO\n";
                return;
            }
            used[q.front()] = 1;
            q.pop();
        }
    }

    cout << "YES\n";
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
