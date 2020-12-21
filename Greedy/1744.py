n = int(input())
arr = [ [], []]
is_zero_existed = False
ans = 0

for i in range(0, n):
    temp = int(input())
    if temp > 0:
        arr[0].append(temp)
    elif temp == 0:
        is_zero_existed = True
    else:
        arr[1].append(temp)

arr[0].sort(reverse=True)
arr[1].sort()

len_plus = len(arr[0])
len_minus = len(arr[1])

if is_zero_existed and (len_minus % 2 == 1):
    del arr[1][-1]
    len_minus -= 1

i = 0
while i < len_plus:
    if i+1 < len_plus and arr[0][i+1] != 1:
        ans += arr[0][i] * arr[0][i+1]
        i += 1
    else:
        ans += arr[0][i]
    i += 1

i = 0
while i < len_minus:
    if i+1 < len_minus:
        ans += arr[1][i] * arr[1][i+1]
        i += 1
    else:
        ans += arr[1][i]
    i += 1

print(ans)
