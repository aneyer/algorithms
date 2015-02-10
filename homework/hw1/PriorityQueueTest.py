import random
import unittest
import PriorityQueue # need to say it comes from another file


class PriorityQueueTest(unittest.TestCase):

    def setUp(self):
        s = PriorityQueue.PriorityQueue() #since module or package need to qualify it with package name first: filename.className

    def test_add(self):
        s = PriorityQueue.PriorityQueue()
        self.assertRaises(TypeError, s.add("yoyo")) 
        self.assertRaises(TypeError, s.add("lal"))
        self.assertRaises(TypeError, s.add(True))
        self.assertRaises(TypeError, s.add(False))
        s.add(2)
        self.assertTrue(2 in s)
        s.add(3.2)
        self.assertTrue(3.2 in s)
        s.add(-100)
        self.assertTrue(-100 in s)

    def test_length(self):
        # test length method
        self.assertEqual(0, s.__len__())
        self.add(22)
        self.assertEqual(1, s.__len__())
#
        # should raise an exception for an immutable sequence
    #    self.assertRaises(TypeError, random.shuffle, (1,2,3))            

if __name__ == '__main__':
    unittest.main()