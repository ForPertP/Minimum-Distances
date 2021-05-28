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
