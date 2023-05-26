#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumDistances' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int minimumDistances(vector<int> a)
{
    int min = a.size();
    std::map<int, int> mp;
    
    for (size_t i = 0, size = a.size(); i < size; ++i)
    {
        auto ret = mp.insert({ a[i], i });
        if (ret.second == false)
        {
            int distance = i - ret.first->second;
            if (distance < min)
            {
                min = distance;
            }
        }        
    }
    
    return (min == a.size()) ? -1 : min;
}


int minimumDistances0(vector<int> a)
{
    int min = a.size();

    for (int i = 0; i < a.size()-1; i++)
    {
        for (int j = i+1; j < a.size(); j++)
        {
            if (a[i] == a[j])
            {
                if (min > (j-i))
                {
                    min = j - i;
                    break;
                }
            }
        }
    }
    
    return (min == a.size()) ? -1 : min;
}
