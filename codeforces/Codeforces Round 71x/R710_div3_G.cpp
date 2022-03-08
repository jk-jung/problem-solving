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
    string s, r;
    cin >> s;
    map<char, int> cnt;
    for (char x: s)cnt[x]++;

    for (int i = 0; i < s.size();) {
        if (cnt[s[i]] == 0){i++; continue;}
        if (cnt[s[i]] == 1) {
            r += s[i];
            cnt[s[i]]--;
            i++;
            continue;
        }
        map<char, int> cur;
        char mm = s[i];
        int j = i;
        while (i < s.size() && cnt[s[i]] - cur[s[i]] > 1) {
            cur[s[i]]++;
            mm = max(mm, s[i++]);
            while (i < s.size() && cnt[s[i]] == 0)i++;
        }
        if (i < s.size())mm = max(mm, s[i++]);

        for (int k = j; k < i; k++) {
            if (cnt[s[k]] == 0)continue;
            cnt[s[k]]--;
            if (s[k] == mm) {
                cnt[s[k]] = 0;
                r += s[k];
                i = k + 1;
                break;
            }
        }
    }
    cout << r << endl;
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
