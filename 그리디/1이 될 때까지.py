n, k = map(int,input().split())

cnt_1 = 0
cnt_2 = 0

while(n):
  if n % k == 0 :
    n /= k
    cnt_2 += 1
  else :
    n -= 1
    cnt_1 += 1

print(min(cnt_1, cnt_2))