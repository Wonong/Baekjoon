n = int(input())

max_with_five = n // 5
ans = -1

for five_nums in range(max_with_five, -1, -1):
    if n == five_nums * 5:
       ans = five_nums
       break

    remained = n - five_nums * 5
    if remained % 3 == 0:
        ans = five_nums + (remained // 3)
        break

print(ans)


