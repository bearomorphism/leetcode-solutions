class Solution:
    def capitalizeTitle(self, title: str) -> str:
        li = title.lower().split()
        for i in range(len(li)):
            if len(li[i]) > 2:
                li[i] = li[i][0].upper() + li[i][1:]

        return ' '.join(li)
