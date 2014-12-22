class Solution:
	# @param S, a list of integer
	# @return a list of lists of integer
	def subsets(self, S):
		result = []
		flags = [0]*len(S)
		for i in range(2**len(S)):
			tmp = []
			s0 = ""
			for j in range(len(S)-1):
				s0 = s0 + "0"
			flag = (s0 + str(bin(i)[2:]))[-len(S):]
			for j in range(len(S)):
				if (flag[j] == "1"):
					tmp.append(S[j])
			tmp.sort()
			result.append(tmp)
		result.sort(self.compare)
		return result

	def compare(self, a, b):
		if len(a)>len(b):
			return 1
		elif len(a)<len(b):
			return -1
		elif a == []:
			return 0
		else:
			for i in range(len(a)):
				if a[i] > b[i]:
					return 1
				if a[i] < b[i]:
					return -1
		return 0
def main():
	s = Solution()
	print s.subsets([0])
main()
