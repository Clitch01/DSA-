/* https://cses.fi/problemset/task/1637 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
int cache[(int)1e6 + 1];

int digit(string total) {
    int nums = stoi(total);
    if (cache[nums] != -1) {
        return cache[nums];
    }
    if (!nums) {
        return 0;
    }
    cache[nums] = INT_MAX;
    int maxx = INT_MIN;
    for (auto &i : total) {
        maxx = max(maxx, i - '0');
    }
    string stress = to_string(nums - (maxx));
    return cache[nums] = min(cache[nums], digit(stress) + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    memset(cache, -1, sizeof(cache));

    cout << digit(s);

    return 0;
}