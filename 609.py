class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        texts = defaultdict(list)
        for path in paths:
            tmp = path.split()
            p = tmp[0]
            for file in tmp[1:]:
                idx = file.find('(')
                filename = file[:idx]
                text = file[idx:-1]
                # print(text)
                texts[text].append(p + '/' + filename)

        result = []
        for value in texts.values():
            if len(value) > 1:
                result.append(value)

        return result
