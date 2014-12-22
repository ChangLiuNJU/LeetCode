class Solution:
    # @return an integer
	def reverse(self, x):
		s = str(x)
		if s[0] == '-':
			return 0-int(s[1:][::-1])
		else:
			return int(str(x)[::-1])
def main():
	s = Solution()
	print s.reverse(100)
main()