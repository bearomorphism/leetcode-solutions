class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> v(26);
        for (int i = 0; i < s.length(); i++)
        {
            v[s[i] - 'a'] = i;
        }
        vector<int> ans;
        int idx = 0;
        while (idx < s.length())
        {
            int st = idx;
            int e = v[s[idx] - 'a'];
            while (idx < e)
            {
                e = max(e, v[s[idx] - 'a']);
                idx++;
            }
            ans.push_back(idx - st + 1);
            idx++;
        }
        return ans;
    }
};