class Solution:
    def simplifyPath(self, path: str) -> str:
        path = path.replace('//', '/')
        nodes = path.split('/')
        lst = []
        for n in nodes:
            if n == '' or n == '.':
                continue
            if n == '..':
                if lst:
                    lst.pop()
                continue
            lst.append(n)
        return '/' + '/'.join(lst)