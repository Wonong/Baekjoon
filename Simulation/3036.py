def gcd(a, b):
    return gcd(b, a%b) if a%b else b

n = int(input())
num_list = input().split()
first_radius = int(num_list[0])

for i in num_list[1:]:
    gcd_num = gcd(first_radius, int(i))
    print('{}/{}'.format(first_radius // gcd_num, int(i) // gcd_num))
