class Solution:
	# @param s, a string
	# @return a string
	def reverseWords(self, s):
		l = s.split()
		l.reverse()
		result = ' '.join(l)
		return result 
def main():
	s = Solution()
	print s.reverseWords(" ")
main()