class Solution
{
public:
    string intToRoman(int num)
    {
        vector<int> v;
        while (num > 0)
        {
            v.push_back(num % 10);
            num /= 10;
        }
        const string r9[] = {"IX", "XC", "CM"},
                     r4[] = {"IV", "XL", "CD"},
                     r5[] = {"V", "L", "D"},
                     r1[] = {"I", "X", "C", "M"};
        string ans;
        for (int i = 3; i >= 0; i--)
        {
            if (i >= v.size() || v[i] == 0)
                continue;
            int x = v[i];
            if (x == 9)
            {
                ans += r9[i];
            }
            else if (x == 4)
            {
                ans += r4[i];
            }
            else
            {
                if (x >= 5)
                {
                    ans += r5[i];
                    x -= 5;
                }
                for (int j = 0; j < x; j++)
                    ans += r1[i];
            }
        }
        return ans;
    }
};