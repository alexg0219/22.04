#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int main()
{
    int n,r;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n ; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> score(n, vector<int>(n));

    for (int i = 2; i <= n; i++)
        for (int j = 0; i + j - 1 < n; j++)
        {
            r = i + j - 1;
            if (i == 2)
            {
                score[j][r] = 0;
            }
            else
            {
                score[j][r] = 2000 * 1000 + 1;
                for (int m = j + 1; m <= r-1; m++)
                    score[j][r] = min(score[j][r], (a[j] + a[r]) * a[m] + score[j][m] + score[m][r]);
                assert(score[j][r] < 100 * 1000 * 1000 + 1);
            }
        }

    cout << score[0][n - 1];
}
