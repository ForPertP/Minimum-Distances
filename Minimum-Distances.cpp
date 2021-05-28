int minimumDistances(vector<int> a)
{
	int min = a.size();
	std::map<int, int> mp;

	for (int i = 0; i < a.size(); ++i)
	{
		if (mp[a[i]])
		{
			int distance = i - mp[a[i]];
			if (distance < min)
			{
				min = distance;
			}
		}
		else
		{
			mp[a[i]] = i;
		}
	}

	if (min == a.size())
	{
		return -1;
	}

	return min;
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

    if ( min == a.size() )
    {
        return -1;
    }
    
    return min;
}
