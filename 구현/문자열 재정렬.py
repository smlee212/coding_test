data = input()
res = []
val = 0

for x in data:
  # 알파벳인 경우 결과 리스트에 삽입
  if x.isalpha():
    res.append(x)
    
  # 숫자는 따로 더하기
  else:
    val += int(x)

res.sort()

# 숫자가 하나라도 존재하는 경우 가장 뒤에 삽입
if val != 0:
  res.append(str(val))

# 최종 결과 출력(리스트를 문자열로 변환하여 출력)
print(''.join(res))