class Solution:
    def mostPopularCreator(self, creators: List[str], ids: List[str], views: List[int]) -> List[List[str]]:
        dic = defaultdict(list)
        for c, i, v in zip(creators, ids, views):
            dic[c].append([-v, i])
        ret = []
        hi = min(sum(value[0] for value in lst) for lst in dic.values())
        for k, v in dic.items():
            if hi == sum(value[0] for value in v):
                ret.append([k, min(v)[1]])
        return ret