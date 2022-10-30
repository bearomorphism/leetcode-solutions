def solution():
    p = 1
    for i in range(365):
        p *= 1 - i / 365
        print(f"{i+1}-th person: {1 - p}")

if __name__ == "__main__":
    solution()
