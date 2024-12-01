with open("day1.txt", 'r') as file:
    l1 = []
    l2 = []

    for line in file:
        fields = line.strip().split()
        l1.append(fields[0])
        l2.append(fields[1])

def part1(l1, l2) -> int:
    sum = 0
    l1.sort()
    l2.sort()

    for _ in range(len(l1)):
        sum += abs(int(l1[0]) - int(l2[0]))
        l1.remove(l1[0])
        l2.remove(l2[0])
    
    return sum

def part2(l1, l2) -> int:
    return sum((int(l1_element) * l2.count(l1_element)) for l1_element in l1)


print(part2(l1, l2))
print(part1(l1, l2))
