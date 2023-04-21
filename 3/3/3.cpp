#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int n, k, p, r;
    vector<char> answers;
    cin >> n >> k >> p;

    for (int i = 1; i <= p; i++) 
    {
        cin >> r;

        if (r == n % (k + 1) || n % (k + 1) == 0) 
        {
            answers.push_back('T');
        }
        else 
        {
            answers.push_back('F');
        }

        n -= r;
    }
 
    for (auto i: answers)
    {
        cout << i << endl;
    }
}