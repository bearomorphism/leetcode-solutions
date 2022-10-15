class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        @lru_cache(None)
        def counter(start, last, last_count, left):
            if left < 0:
                return float('inf')
            if start >= len(s):
                return 0
            if s[start] == last:
                incr = 1 if last_count in [1, 9, 99] else 0
                return incr + counter(start + 1, last, last_count + 1, left)
            keep_cnt = 1 + counter(start + 1, s[start], 1, left)
            del_cnt = counter(start + 1, last, last_count, left - 1)
            return min(keep_cnt, del_cnt)
        return counter(0, None, 0, k)
