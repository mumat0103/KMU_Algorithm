n = int(input())

a = list(map(int, input().split()))
w = [1, 2, 5, 10, 20, 50, 100]
left = a[0]
right = a[1]

for i in range(2, n):
    if left == right:
        left += a[i]
    else:
        if left < right:
            left += a[i]
        elif right < left:
            right += a[i]
            

sub = left-right
if sub < 0:
    sub = -sub
d = [10000001] * (sub + 1)
d[0] = 0
for i in range(7):
    for j in range(w[i], sub + 1):
        d[j] = min(d[j], d[j - w[i]] + 1)

print(d[sub])