'''
input: array
at most
>= 0
N >= 1
[2, 1, 3]

0
[4, 5, 1, 2, 3, 4]
4
'''

def solution2(arr):
    n = len(arr)
    l = 0
    r = 0
    ans = 0
    while r < n - 1:
        tmp = r
        for i in range(l, r + 1):
            r = max(r, i + arr[i])
            if r >= n - 1:
                return ans + 1
        l = tmp + 1
        ans += 1
    return ans


def solution(arr):
    n = len(arr)
    dp = [0] * n
    for i in reversed(range(n - 1)):
        arg = dp[i + 1: min(n, i + arr[i] + 1)]
        if not arg:
            dp[i] = 99999999
        else:
            dp[i] = min(arg) + 1
    return dp[0]


if __name__ == '__main__':
    print(solution2([2,3,0,1,4]))
    print(solution2([2,1,3]))
    print(solution2([2,0,3]))
    print(solution2([2,1]))
