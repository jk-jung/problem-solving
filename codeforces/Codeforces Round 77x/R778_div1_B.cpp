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
    string s;
    cin >> s;
    vi used(s.size());
    map<char, queue<int>>ck;
    for(int i=0;i<s.size();i++)ck[s[i]].push(i);
    for(int i=0;i<s.size();i++){
        char x = s[i];
        queue<int> &q = ck[x];
        if(q.size() == 1) {
            for(int j=i;j<s.size();j++){
                if(used[j])continue;
                cout << s[j];
            }
            cout << endl;
            return;
        }
        used[q.front()] = 1;
        q.pop();
    }
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
