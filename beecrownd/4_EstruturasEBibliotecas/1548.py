tests = int(input())

for _ in range(tests):
    students = int(input())
    list_students_sorted = list(map(int, input().split()))
    list_students = list_students_sorted.copy()
    list_students_sorted.sort(reverse=True)
    unchanged_students = 0
    for i in range(students):
        if (list_students[i] == list_students_sorted[i]):
            unchanged_students += 1
    print(unchanged_students)
