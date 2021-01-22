n, k = map(int,input().split())

res = 0
while True:
  target = (n//k) * k # n에 가까운 k의 배수
  res += n - target # 1을 빼는 횟수
  n = target

  if n < k:
    break
  
  res += 1
  n //= k

res += (n-1)
print(res)