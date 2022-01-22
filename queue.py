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
    
s = Queue()
while True:
    print('enqueue <value>')
    print('dequeue')
    print('view')
    print('quit')
    do = input('What would you like to do? ').split()
 
    operation = do[0].strip().lower()
    if operation == 'enqueue':
        s.push(int(do[1]))
    elif operation == 'view':
        s.view()
    elif operation == 'dequeue':
        if s.isEmpty():
            print('Stack is empty.')
        else:
            print('Popped value: ', s.pop())
    elif operation == 'quit':
        break