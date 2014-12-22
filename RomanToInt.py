class Solution:
	# @return an integer
	def ctoi(self, c):
		if   c == 'I':
			return 1
		elif c == 'V':
			return 5
		elif c == 'X':
			return 10
		elif c == 'L':
			return 50
		elif c == 'C':
			return 100
		elif c == 'D':
			return 500
		elif c == 'M':
			return 1000
	def romanToInt(self, s):
		result = 0
		prv = 1001
		for c in s:
			i = self.ctoi(c)
			if i <= prv:
				result += i
			else:
				result = result + i - prv*2
			prv = i
		return result
def main():
	s = Solution()
	print s.romanToInt('MCMLXXVI')
	
main()


