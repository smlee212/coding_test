n, m = map(int,input().split())

res = 0
for _ in range (n):
  data = list(map(int,input().split()))
  min_val = min(data)
  res = max(res, min_val)

print(res)