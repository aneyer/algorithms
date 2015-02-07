class Stack:
    def __init__(self):
        self.data = []

    def add(self, x):
        self.data.append(x)

    def remove(self):
        return self.data.pop()

    def __str__(self):
        return str(self.data)
		
    def hi(self):
		print 'hi'

s = Stack()
s.add(4)
s.add("dog")
s.add(True)
print 'I just popped ', s.remove()
## print 'the length is: 
## ' len(s.__str__())
print 'the length is: ', len(s.__str__())
print s
s.hi()