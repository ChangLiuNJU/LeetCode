# Definition for a  binary tree node
class TreeNode:
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None

class Solution:
	# @param num, a list of integers
	# @return a tree node
	def sortedArrayToBST(self, num):
		if len(num) == 0:
			return None
		pivot = len(num) / 2
		root = TreeNode(num[pivot])
		root.left  = self.sortedArrayToBST(num[ : pivot])
		root.right = self.sortedArrayToBST(num[pivot + 1 : ]) 
		return root
def printTree(root, tab):
	if root == None:
		return
	s = ""
	for i in range(tab):
		s += " "	
	print s + str(root.val)
	printTree(root.left, tab + 1)
	printTree(root.right, tab + 1)
def main():
	s = Solution()
	l = [1, 2, 3, 4, 5, 6, 7, 8, 9]
	r = s.sortedArrayToBST(l)
	printTree(r, 0)
main()
