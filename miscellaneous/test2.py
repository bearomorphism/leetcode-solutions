from scipy.special import binom
from math import factorial

# def f(x):
#     return binom(20, x) * 0.7 ** x * 0.3 ** (20 - x)


# print(sum(f(x) for x in range(14, 21)))
# print(f(9))
# print(sum(f(x) for x in range(18, 21)))
# print(sum(f(x) for x in range(21)))

# print(3 ** 8 / 16 ** 8 * factorial(8) / factorial(3) / factorial(3))
# print(1 - (1 / binom(25, 5) * (binom(20, 5) + 5 * binom(20, 4))))
# print(.9 ** 8 * .06 ** 3 * .04 * factorial(12) / factorial(8) / factorial(3))

def f(*args, **kwargs):
    print(f"{args=}")
    print(sum(args))
    print(f"{kwargs=}")

f(1,2,3,4, abc=123, de=456)