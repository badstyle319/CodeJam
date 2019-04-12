def solve(s):
	idx = len(s)
	for i,ch in enumerate(s):
		if ch=='4':
			idx = min(idx, i)
			print('1', end='')
		else:
			print(ch, end='')
	print(' ', end='')
	for i,ch in enumerate(s):
		if ch=='4':
			print('3', end='')
		elif i>idx:
			print('0', end='')
	print()
			
T = int(input())
for caseNo in range(1, 1+T):
	str=input()
	print("Case #%d: "%caseNo, end='')
	solve(str)