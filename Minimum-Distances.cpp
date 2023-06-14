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
 int minimumDistances(vector<int>& a)
{
    int min = a.size();
    size_t size = a.size();
    std::unordered_map<int, int> mp;

    for (size_t i = 0; i < size; ++i)
    {
        auto [it, inserted] = mp.try_emplace(a[i], i);
        if (!inserted)
        {
            int distance = i - it->second;
            if (distance < min)
            {
                min = distance;
                if (min == 1)
                    break;
            }
        }
    }

    return (min == a.size()) ? -1 : min;
}


int minimumDistances1(vector<int>& a)
{
    int min = a.size();
    std::unordered_map<int, int> mp;

    size_t size = a.size();
    for (size_t i = 0; i < size; ++i)
    {
        auto ret = mp.insert({ a[i], i });
        if (!ret.second)
        {
            int distance = i - ret.first->second;
            if (distance < min)
            {
                min = distance;
                if (min == 1)
                    break;
            }
        }
    }

    return (min == a.size()) ? -1 : min;
}


int minimumDistances2(vector<int>& a) {
    int minDistance = a.size();
    unordered_map<int, int> mp;
    
    for (int i = 0; i < a.size(); ++i) {
        if (mp.count(a[i])) {
            int distance = i - mp[a[i]];
            if (distance < minDistance) {
                minDistance = distance;
            }
        }
        mp[a[i]] = i;
    }
    
    return (minDistance == a.size()) ? -1 : minDistance;
}


int minimumDistances3(vector<int>& a)
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

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
