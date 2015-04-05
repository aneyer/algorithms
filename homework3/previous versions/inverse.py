def inverse(x, p):
    inv1 = 1
    inv2 = 0
    while p != 1:
        inv1, inv2 = inv2, inv1 - inv2 * (x / p)
        x, p = p, x % p
    return inv2