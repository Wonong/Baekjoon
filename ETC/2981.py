def gcd(a, b):
    return gcd(b, a%b) if a%b else b

n = int(input())

num_list = []
ans_list = []

for i in range(0, n):
    num_list.append(int(input()))
num_list.sort()

gcd_num = num_list[1] - num_list[0]
for i in range(2, n):
    gcd_num = gcd(gcd_num, num_list[i] - num_list[i-1])

j = 2
while j*j <= gcd_num:
    if gcd_num % j == 0:
        ans_list.append(j)
        if gcd_num // j != j:
            ans_list.append(gcd_num // j)
    j += 1
ans_list.append(gcd_num)
ans_list.sort()

for i in ans_list:
    print(i)
