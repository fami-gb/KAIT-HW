def find_max(list1):
    max1 = list1[0]
    for i in range(len(list1)):
        if (max1 < list1[i]):
            max1 = list1[i]
    return max1

list1 = [0, 1, 2, 3]
print(find_max(list1))
