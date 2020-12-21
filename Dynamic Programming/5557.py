n = int(input())
num = input().split(' ')
num = [int(i) for i in num]
dp = [[0 for i in range(0, 21)] for i in range(0, n)]

dp[0][num[0]] = 1

for i in range(1, n-1):
    for j in range(0, 21):
        if dp[i-1][j] > 0:
            if j + num[i] <= 20:
                dp[i][j + num[i]] += dp[i-1][j]
            if j - num[i] >= 0:
                dp[i][j - num[i]] += dp[i-1][j]

print(dp[n-2][num[n-1]])

