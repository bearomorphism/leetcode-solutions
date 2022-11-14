# def f(x, y):
#     return x*y / (x + y)

# print(f(f(10, 20), 30))
# print(f(10, f(20, 30)))

itm = [
    (3, 10),
    (4, 12),
    (5, 18),
    (4, 19),
    (7, 20),
    (8, 19),
    (5, 12)
]

lst = [0] + [-1] * 18

for w, p in itm:
    for i in range(18 - w, -1, -1):
        if lst[i] != -1:
            lst[i + w] = max(lst[i + w], lst[i] + p)

print(lst[18])