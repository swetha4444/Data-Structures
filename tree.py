'''
class node:
    def __init__(self) -> None:
        self.data
        self.childern = [] #objects
''' 

class Queue:
    def __init__(self) -> None:
        self.items = []
        
    def enqueue(self,data):
        self.items.append(data)
    
    def dequeue(self):
        return self.items.pop(0)
    
    def isEmpty(self):
        return (len(self.items) == 0)

    def view(self):
        print(self.items)

class Stack:
    def __init__(self) -> None:
        self.items = []
    
    def push(self,data):
        self.items.append(data)
    
    def pop(self):
        return self.items.pop()
    
    def isEmpty(self):
        return (len(self.items) == 0)

    def view(self):
        print(self.items)

class node:
    def __init__(self) -> None:
        self.data = 0
        self.left = None
        self.right = None
        

#! Traversal  
def inorder(root):
    #LEFT-ROOT-RIGHT
    if root:
        inorder(root.left)
        print(root.data)
        inorder(root.right)
    

def preorder(root):
    #ROOT-LEFT-RIGHT
    if root:
        print(root.data)
        preorder(root.left)
        preorder(root.right)

def postorder(root):
    #LEFT-RIGHT-ROOT
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.data)
    

#! Search
def bfs(root,key):
    q = Queue()
    if root:
        q.enqueue(root)
        
    while(not q.isEmpty()):
        
        node = q.dequeue()
        if(node.data == key):
            return True
         
        if node.left:
            q.enqueue(node.left)
            
        if node.right:
            q.enqueue(node.right)        
    return False

def dfs(root,key):
    q = Stack()
    if root:
        q.push(root)
        
    while(not q.isEmpty()):
        
        node = q.pop()
        if(node.data == key):
            return True
         
        if node.left:
            q.push(node.left)
            
        if node.right:
            q.push(node.right)        
    return False

#! Depth
def min_depth(root,level):
    if(root == None):
        return level
    level += 1
    return min(min_depth(root.left,level),min_depth(root.right,level))

def max_depth(root,level):
    if(root == None):
        return level
    level += 1
    return max(max_depth(root.left,level),max_depth(root.right,level))
      
#----------------------------------------------------------------------------------------------------------#
root = node()
root.data = 2

root.left = node()
root.left.data = 3

root.right = node()
root.right.data = 4

root.left.left = node()
root.left.left.data = 5

root.left.right = node()
root.left.right.data = 7

key = int(input("Enter key to search: "))
if dfs(root,key):
    print("DFS: Found")
else:
    print("DFS: Not Found")
    
if bfs(root,key):
    print("BFS: Found")
else:
    print("BFS: Not Found")

print("Minimum depth of the tree: ",min_depth(root,0))
print("Maximum height of the tree: ",max_depth(root,0))