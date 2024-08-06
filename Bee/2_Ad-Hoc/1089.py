while True:
    entry = int(input())
    if (entry == 0):
        break
    array = list(map(int, input().split(' ')))
    cout = 0
    for i in range(1, entry-1):
        if array[i] > array[i+1] and array[i] > array[i-1]:
            cout += 1
        elif array[i] < array[i+1] and array[i] < array[i-1]:
            cout += 1
    if array[entry - 1] > array[entry - 2] and array[entry - 1] > array[0]:
        cout += 1
    elif array[entry - 1] < array[entry - 2] and array[entry - 1] < array[0]:
        cout += 1
    if array[0] > array[1] and array[0] > array[entry - 1]:
        cout += 1
    elif array[0] < array[1] and array[0] < array[entry - 1]:
        cout += 1
    print(cout)