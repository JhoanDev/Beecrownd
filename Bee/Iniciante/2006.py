target = input()
array = input().split(' ')

count = 0
for x in array:
    if x == target:
        count += 1

print(count)
