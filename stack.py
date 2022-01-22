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
    
s = Stack()
while True:
    print('push <value>')
    print('pop')
    print('view')
    print('quit')
    do = input('What would you like to do? ').split()
 
    operation = do[0].strip().lower()
    if operation == 'push':
        s.push(int(do[1]))
    elif operation == 'view':
        s.view()
    elif operation == 'pop':
        if s.isEmpty():
            print('Stack is empty.')
        else:
            print('Popped value: ', s.pop())
    elif operation == 'quit':
        break