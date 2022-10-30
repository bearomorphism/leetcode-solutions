class Solution:
    def destroyTargets(self, nums: List[int], space: int) -> int:
        dic = defaultdict(list)
        for num in nums:
            dic[num % space].append(num)
        maxi = max(len(lst) for lst in dic.values())
        ret = float('inf')
        for lst in dic.values():
            if maxi == len(lst):
                ret = min(ret, min(lst))
        return ret
