class Node:
	def __init__(self, value):
		self.value=value
		self.left=None
		self.right=None

class BST:
	def __init__(self):
		    self.root = None 
	
	def insert(self, root, value):
		if root is None:
			return Node(value)
		
		if value < root.value:
			root.left = self.insert(root.left, value)
		elif value > root.value:
			root.right = self.insert(root.right, value)
		
		return root
	
	def inorder(self, root):
		if root: 
			self.inorder(root.left)
			print(root.value, end=" ")
			self.inorder(root.right)
	
	def preorder(self, root):
		if root: 
			print(root.value, end=" ")
			self.preorder(root.left)
			self.preorder(root.right)
		
	def postorder(self, root):
		if root: 
			self.postorder(root.left)
			self.postorder(root.right)
			print(root.value, end=" ")

tree = BST()

tree.root = tree.insert(tree.root, 10)
tree.root = tree.insert(tree.root, 20)
tree.root = tree.insert(tree.root, 34)

print("Preorder: ", end="")
tree.preorder(tree.root)

print("\nInorder: ", end="")
tree.inorder(tree.root)

print("\nPostorder: ", end="")
tree.postorder(tree.root)


