n = int(input())

cnt = 0
for i in range(n+1): # 00시 부터 n시 까지
  for j in range(60): # 분 
    for k in range(60): # 초
      if '3' in str(i) + str(j) + str(k): # 이 안에 3이 있는지 확인
        cnt += 1

print(cnt)