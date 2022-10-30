'''
Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.

Example 1:
Input: ["23:59", "00:00"]
Output: 1
'''

def toMinutes(s):
    hour, minute = map(int, s.split(':'))
    return hour * 60 + minute


def solution(times):
    minutes = list(map(toMinutes, times))
    minutes.sort()
    result = 1440 - (minutes[-1] - minutes[0])
    for i in range(len(minutes) - 1):
        result = min(result, minutes[i + 1] - minutes[i])
    return result


if __name__ == '__main__':
    print(solution(["23:59", "00:00"]))
    print(solution(["23:58", "00:00"]))
    print(solution(["23:00", "00:00"]))
    print(solution(["11:00", "00:00"]))
    print(solution(["13:00", "00:00"]))
    print(solution(["01:00", "03:00", "02:00"]))
