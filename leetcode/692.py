class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        cnt = defaultdict(int)
        for word in words:
            cnt[word] += 1
        lst = sorted(cnt.items(), key=lambda x: (-x[1], x[0]))
        return [u[0] for u in lst[:k]]

