n, m ,k = map(int, input().split())

data = list(map(int,input().split()))

data.sort()
firstBig = data[n-1]
secondBig = data[n-2]

res = 0
cnt = 1

for _ in range (m) :
  if cnt % k == 0 :
    res += secondBig
  else :
    res += firstBig
  cnt += 1

print(res)