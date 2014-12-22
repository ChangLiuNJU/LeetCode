class Solution:
	# @param tokens, a list of string
	# @return an integer
	def evalRPN(self, tokens):
		i = 0
		operator = ['+', '-', '*', '/']
		calculation = {'+':lambda x, y: x + y,
					   '-':lambda x, y: x - y,
					   '*':lambda x, y: x * y,
					   '/':lambda x, y: int(float(x) / float(y))}		
		while i < len(tokens):
			if tokens[i] in operator:
				a = int(tokens[i - 2])
				b = int(tokens[i - 1])
				tokens[i] = str(calculation[tokens[i]](a, b))
				del tokens[i - 1]
				del tokens[i - 2]
				i = i - 2
			i = i + 1
		return int(tokens[0]) 
def main():
	s = Solution()
	l = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"] 
	print s.evalRPN(l)	
main()        