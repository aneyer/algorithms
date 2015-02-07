class PriorityQueue:
    def __init__(self):
        self.data = []
		
    def add(self, item):
       # if (isinstance(item, int) or isinstance(item, long) or isinstance(item, float) or isinstance(item, complex)): #run through rest of code if item added is a number (int, long, float, or complex)
        self.data.append(item)
        self.sift_up(len(self.data) - 1)
        return self
      #  else: 
      #      raise TypeError, "You can only add numbers."
		
    def peek(self):
		# pass is a method stub in python
		#pass
        if len(self.data) == 0:
            raise ValueError, "You are trying to pop an empty queue. Don't. It's an Empty Queue!"
        return self.data[0]
		
    def remove(self):
        top = self.peek(); # return value at top
        self.data[0] = self.data[len(self.data) - 1] # replace top node with value of last slot
        self.data.pop() # destroy last slot
        self.sift_down(0) #sift down
        return top

    def __len__(self):
		return len(self.data);
    
    def __str__(self):
        return str(self.data)

    # sift up the element at index i
    def sift_up(self, i):
        parent = (i-1)/2
        if parent >=0 and self.data[parent] > self.data[i]:
            self.data[parent], self.data[i] = self.data[i], self.data[parent]  #data[parent] switched with data[i] and data[i] switched with data[parent] value in one line on python
            self.sift_up(parent)

    # sift down the element at index i
    def sift_down(self, i):
        child = (i*2)+1
        if child < len(self.data): ## stops if you don't have kids or if you have exceeded queue's list
        ## do i have 2nd kid and is that kid the smallest. if i am bigger than my kid then flip parent with kid. put smaller kid in the parent's spot. ifparent is smaller then kid then stop and parent at position tehy want to be
            if child+1 < len(self.data) and self.data[child +1] < self.data[child]: # is 2nd kid within bounds of queue and is kid2 < firstkid
                child = child + 1            
            if self.data[i] > self.data[child]:
                self.data[i], self.data[child] = self.data[child], self.data[i]
                self.sift_down(child) # call function to check child location index and repeat process






s = PriorityQueue()
test2 = PriorityQueue()
test2.add("dog")
test2.add(92)
test2.add(True)
test2.add(1)
print 'The toString method of test2 says: ', test2.__str__()
print ' I just popped ', test2.remove()
print 'The toString method of test2 says: ', test2.__str__()
s.add(4)
s.add(5)
s.add(9.9)
print 'I just popped ', s.remove()
print 'the length is: ', len(s.__str__())
print 'The toString method output: ', s.__str__()
print s
print 'peek is being called. I just peeked and the following appeared: ', s.peek()

