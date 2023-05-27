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
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = minimumDistances(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}
    
    return (min == a.size()) ? -1 : min;
}
