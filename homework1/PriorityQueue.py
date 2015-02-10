class PriorityQueue:
    def __init__(self):
        self.data = []
		
    def add(self, item):
        if (isinstance(item, int) or isinstance(item, long) or isinstance(item, float) or isinstance(item, complex)): #run through rest of code if item added is a number (int, long, float, or complex)
            self.data.append(item)
            self.sift_up(self.__len__() - 1)
            return self
        else: 
            raise TypeError, "You can only add numbers."

    def is_empty(self):
        if self.__len__() == 0:
            return True
        else: 
            return False 
		
    def peek(self):
		# pass is a method stub in python
		#pass
        if self.is_empty():
            raise ValueError, "You are trying to pop an empty queue. Don't. It's an Empty Queue!"
        return self.data[0]
		
    def remove(self):
        if(self.__len__()==1):
            self = []
        else:
            top = self.peek(); # return value at top
            self.data[0] = self.data[self.__len__() - 1] # replace top node with value of last slot
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
        if child < self.__len__(): # stops if you don't have kids or if you have exceeded queue's list
        # Do I have 2nd kid and is that kid the smallest? If I am bigger than my kid then flip parent with kid. put smaller kid in the parent's spot. If parent is smaller then kid then stop and parent at position they want to be
            if child+1 < self.__len__() and self.data[child +1] < self.data[child]: # is 2nd kid within bounds of queue and is kid2 < firstkid
                child = child + 1            
            if self.data[i] > self.data[child]:
                self.data[child], self.data[i] = self.data[i], self.data[child]
                self.sift_down(child) # call function to check child location index and repeat process





"""
s = PriorityQueue()
test2 = PriorityQueue()
test1 = PriorityQueue()
print test1
print 'The length of test1 is: ', test1.__len__()
test1.add(1000.99)
print 'The length of test1 is: ', test1.__len__()
print test1

test2.add(1)
test2.add(92)
test2.add(7)
test2.add(0)
test2.add(1)
print 'The toString method of test2 says: ', test2.__str__()
# print 'In test2, I just removed: ', test2.remove()
# print 'In test2, I just removed: ', test2.remove()
print 'I am removing' 
print test2.remove()
print test2.remove()
print 'In test2, I just added a 2: ', test2.add(2)
print 'In test2, I just removed: ', test2.remove()
test2.add(4)
print 'peeked in test2: ', test2.peek()
test2.add(0)
test2.add(2)
print 'peeked in test2: ', test2.peek()
print 'test2: ', test2.__str__()
test2.remove()
print 'test2: ', test2.__str__()
print 'The length of test2 is: ', test2.__len__()

print 's is: ', s.__str__()
s.add(4)
s.add(5)
s.add(9.9)
print 's is: ', s.__str__()
print 'In s, I just popped ', s.remove()
print 'The length of s is: ', s.__len__()
print 'The toString method output of s is: ', s.__str__()
print s
print 'peek is being called. I just peeked in s and the following appeared: ', s.peek()
"""