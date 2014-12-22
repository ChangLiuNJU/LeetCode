class Solution:
	def moveStarSeq(self, p):
		if len(p) < 2:
			return p
		else:
			for i in range
	def isMatch(self, s, p):
		if len(s) == 0:
			if len(p) == 0:
				return True
			else:
				for i in range(len(p)):
					if p[i] != '*':
						return False
				return True
		if len(p) == 0:
			return False
		if len(s) == 1 and len(p) != 1:
			count = 0
			for i in range(len(p)):
				if p[i] == '*':
					continue
				elif p[i] == '?' or p[i] == s[0]:
					count += 1
				elif p[i] != s[0]:
					return False
				if count > 1:
					return False
			return True
		elif len(s) == 1 and len(p) == 1:
			return p[0] == '?' or p[0] == '*' or s[0] == p[0]
		elif len(s) != 1 and len(p) == 1:
			return p[0] == '*'

		for i in range(1, len(p)):
			if p[i] == '*' and p[i-1] == '*'


		if p[0] != '*' and p[0] != '?':
			if s[0] == p[0]:
				return True and self.isMatch(s[1:], p[1:])
			else:
				return False
		elif p[0] == '?':
			return True and self.isMatch(s[1:], p[1:])
		elif p[0] == '*':
			tmp = False
			for i in range(len(s)):
				tmp = tmp or self.isMatch(s[i:], p[1:])
				if tmp == True:
					return True
			return False
		return True

def main():
	s = Solution();
	print "1"[2:]
	print s.isMatch("aa","a")
	print s.isMatch("aa","aa")
	print s.isMatch("aaa","aa")
	print s.isMatch("aa","*")
	print s.isMatch("aa","a*")
	print s.isMatch("ab","?*")
	print s.isMatch("aab","c*a*b")
	print s.isMatch("abbbc", "a*bc")
	print s.isMatch("", "")
main()