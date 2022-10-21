class LinkedListNode:
    def __init__(self, val, next = None):
        self.val = val
        self.next = next


def sol(A, B):
    result = None
    cur_node = None
    cur_a = A
    cur_b = B
    incr = 0
    while cur_a or cur_b:
        val_a = cur_a.val if cur_a else 0
        val_b = cur_b.val if cur_b else 0

        summation = val_a + val_b + incr
        node = LinkedListNode(summation % 10)
        incr = summation // 10

        if cur_a:
            cur_a = cur_a.next
        if cur_b:
            cur_b = cur_b.next

        if not result:
            result = node
            cur_node = result
        else:
            cur_node.next = node
            cur_node = cur_node.next

    if incr != 0:
        cur_node.next = LinkedListNode(incr)

    return result

# if __name__ == "__main__":
#     A = [1,3,5,7,9]
#     B = [2,4,6,7,8,9]
#     print(sol(A, B))


'''
def sol(A, B):
    result = []
    i, j = 0, 0
    while i < len(A) and j < len(B):
        if A[i] < B[j]:
            result.append(A[i])
            i += 1
        else:
            result.append(B[j])
            j += 1
    while i < len(A):
        result.append(A[i])
        i += 1
    while j < len(B):
        result.append(B[j])
        j += 1
    return result


if __name__ == "__main__":
    A = [1,3,5,7,9]
    B = [2,4,6,7,8,9]
    print(sol(A, B))
'''
