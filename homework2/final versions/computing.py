class Computing:
    def modDoubleExp(self, a, b, c, p):
        # a^b^c mod p
        pow1 = self.exp(b,c)
        pow2 = self.exp(a,pow1)
        answer = pow2 
        answer = answer % p
        return answer

    def exp(self, a, power):
        for x in range(0, power):
            output = a
            output = a * output
        return output




"""
s = Computing()
print 'modDoubleExp 1^2^3 mod4', s.modDoubleExp(1,2,3,4)
print 'modDoubleExp 2^2^3 mod4', s.modDoubleExp(2,2,3,4)
print 'modDoubleExp 2^3^3 mod1', s.modDoubleExp(2,3,3,1)
print 'modDoubleExp 6^2^3 mod4', s.modDoubleExp(6,2,3,4)

"""