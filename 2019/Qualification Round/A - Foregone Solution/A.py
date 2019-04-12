def solve(s):
	idx = len(s)
	for i in range(len(s)):
		if s[i]=='4':
			idx = min(idx, i)
			print('1', end='')
		else:
			print(s[i], end='')
	print(' ', end='')
	for i in range(len(s)):
		if s[i]=='4':
			print('3', end='')
		elif i>idx:
			print('0', end='')
	print()
			
T = int(input())
for caseNo in range(1, 1+T):
	str=input()
	print("Case #{}: ".format(caseNo), end='')
	solve(str)