class Solution:
    # @param n, an integer
	# @return an integer
	def climbStairs(self, n):
		n = n + 1
		t = 2.23606797749979
		result = (((1 + t)/2)**n - ((1 - t)/2)**n)/t
		return int(round(result.real))

def main():
	s = Solution()
	print s.climbStairs(35)
main()
			        
