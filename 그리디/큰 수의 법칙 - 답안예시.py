n, m, k = map(int,input().split())

data = list(map(int,input().split()))

fBig = data[n-1]
sBig = data[n-2]

cnt = int(m/(k+1)) * k
cnt += m % (k+1)

res = 0
res += cnt * fBig
res += (m - cnt) * sBig

print(res)