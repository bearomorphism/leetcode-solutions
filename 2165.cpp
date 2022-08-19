class Solution
{
public:
    long long smallestNumber(long long num)
    {
        if (num == 0)
            return 0;
        bool neg = num < 0;
        vector<int> digits;
        int cnt = 0;
        if (neg)
            num = -num;
        while (num)
        {
            int x = num % 10;
            if (x)
                digits.push_back(x);
            else
                cnt++;
            num /= 10;
        }
        sort(digits.begin(), digits.end());
        if (neg)
            reverse(digits.begin(), digits.end());
        long long res = 0;
        for (int i = 0; i < digits.size(); i++)
        {
            res = res * 10 + digits[i];
            if (!neg && i == 0 || neg && i == digits.size() - 1)
            {
                for (int j = 0; j < cnt; j++)
                    res = res * 10;
            }
        }
        return neg ? -res : res;
    }
};