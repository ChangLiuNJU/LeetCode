class Solution:
	# @param A, a list of integer
	# @return an integer
	def singleNumber(self, A):
		for i in range(1,len(A)):
			A[i] = A[i] ^ A[i-1]
		return A[-1]
def main():
	s = Solution()
	print s.singleNumber([1,1,3,2,2])
main()    