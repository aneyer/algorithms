def multiplicative_inverse(a, b):
    origA = a
    X = 0
    prevX = 1
    Y = 1
    prevY = 0
    while b != 0:
        temp = b
        quotient = a/b
        b = a%b
        a = temp
        temp = X
        a = prevX - quotient * X
        prevX = temp
        temp = Y
        Y = prevY - quotient * Y
        prevY = temp

    return origA + prevY

print 'modinv: ', multiplicative_inverse(17,391) 