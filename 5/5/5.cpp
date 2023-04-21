#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int n;
    int e, f;
    vector<int> Max, Min;

    cin >> e >> f;
    cin >> n;
    
    Max = vector<int>(f - e + 1, INT_MIN);
    Min = vector<int>(f - e + 1, INT_MAX);
    vector<int> p(n);
    vector<int> w(n);
   
    for (int i = 0; i < n; i++)
        cin >> p[i] >> w[i];
    
    Min[0] = 0;
    Max[0] = 0;

    for (int i = 0; i < Min.size(); i++)
    {
        for (int j = 0; j < w.size(); j++)
        {
            if (i - w[j] >= 0 && Min[i - w[j]] != INT_MAX)
            {
                Min[i] = min(Min[i], Min[i - w[j]] + p[j]);
                Max[i] = max(Max[i], Max[i - w[j]] + p[j]);
            }
        }
    }

    if (Min.back() == INT_MAX)
        cout << "This is impossible.";
    else
        cout << Min.back() << ' ' << Max.back();
}