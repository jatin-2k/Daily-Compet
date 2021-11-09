long long findNthFibonacci(int number)
    {
        vector<long long> v;
        v.push_back(0);
        v.push_back(1);
        for(int i = 2 ; i <= number ; i++)
        {
            v.push_back(v[i-1] + v[i-2]);
        }
        return v[number];
    }