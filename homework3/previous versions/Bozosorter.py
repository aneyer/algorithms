##I modified the following program from http://excode.io/code/27/bozosort/python
import random

#Returns whether list is sorted
def is_sorted(list):
    for i in range(1, len(list)):
        if list[i-1] > list[i]:
            return False
    return True

"""
 Does a bozosort and returns the number of swaps required to sort.
""" 
def bozosort(list):
    swaps = 0
    while not is_sorted(list):
        # get random items to swap
        index_1 = random.randint(0, len(list)-1)
        index_2 = random.randint(0, len(list)-1)
        
        if index_1 != index_2:
            # swap
            temp_holder = list[index_2]
            list[index_2] = list[index_1]
            list[index_1] = temp_holder
            swaps = swaps+1
    #while/else is similar to if/else, but there is a difference: the else block will execute anytime the loop condition is evaluated to False. 
    #This means that it will execute if the loop is never entered or if the loop exits normally. If the loop exits as the result of a break, the else will not be executed.   
    else:
        return swaps
"""
Returns a randomly filled in integer list for a given size
"""
def random_list (size):
    list = []  
    list.append(random.randint(0, size-1))
    return list

if __name__ == "__main__":
    # try 10 sorts 
    iterations = 40
    print 'Size   Average number of swaps'
    print '------------------------------'
    total_swaps = 0
    for trial_size in range (1, 15):
        total_swaps = 0
        for k in range(0, iterations):
            #x = random_list(trial_size)
            #print 'rand list', x
            #x = bozosort(random_list(trial_size))
            #print x 
            #total_swaps = total_swaps + bozosort(x)
            total_swaps = total_swaps + bozosort(random_list(trial_size))
            #print 'total swaps in inner for loop: ', total_swaps
        else:
            print '%2d%20.2f\n' %(trial_size, total_swaps/iterations)
            #total_swaps = 0
    
    list = [5, 15, 14, 1, -6, 26, -100, 0, 99]
    list2 = [5, 9,7]
    
    print 'Initial:'
    print ' '.join([str(i) for i in list])
    
    total_swaps = bozosort(list)
    print 'Total Swaps: ', total_swaps
    print 'avg swaps', (total_swaps/2)
    print '\nResult:'
    print ' '.join([str(i) for i in list])


    print 'Initial:'
    print ' '.join([str(i) for i in list2])
    
    total_swaps = bozosort(list)
    print 'Total Swaps: ', total_swaps
    print 'avg swaps', (total_swaps/2)
    print '\nResult:'
    print ' '.join([str(i) for i in list2])