int minimumDistances(vector<int> a)
{
    int min = a.size();
    std::map<int, int> mp;
    
    for (int i = 0; i < a.size(); ++i)
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
