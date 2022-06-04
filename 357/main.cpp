class Solution
{
private:
    int calc(int digits)
    {
        int ret = 9;
        for (int i = 0; i < digits - 1; i++)
        {
            ret *= 9 - i;
        }
        return ret;
    }

public:
    int countNumbersWithUniqueDigits(int n)
    {
        int ret = 1;
        for (int i = 0; i < n; i++)
        {
            ret += calc(n - i);
        }
        return ret;
    }
};