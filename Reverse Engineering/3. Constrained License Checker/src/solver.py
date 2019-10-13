from z3 import *

def main():
    ks = BitVecs('k0 k1 k2 k3 k4 k5 k6 k7 k8 k9 k10 k11 k12 k13 k14 k15', 8)
    s = Solver()

    s.add(ks[3] == ks[1])
    s.add(ks[2] == ord('a'))
    s.add(ks[15] == ks[2])
    s.add(ks[1] == ord('b'))
    s.add(ks[13] == ks[0]+3)
    s.add(ks[0]-7 == ord('d'))
    s.add(ks[4]+ks[5] == ks[6]^ks[7])
    s.add(ks[8] == ks[11])
    s.add(ks[9]-ks[8] == -2)
    s.add(ks[14] == ord('8'))
    s.add(ks[12]^0xff == 0xa7)
    s.add(ks[7] == ord('6'))
    s.add(ks[6] == ord('z')-25)
    s.add(ks[5] == ord('9')-12)
    s.add(ks[8]-7 == 97)
    s.add(ks[10] == ord('Y'))
    for k in ks:
        s.add(k >= 32)
        s.add(k <= 126)

    while s.check() == sat:
        m = s.model()
        print(m)
        s.add(Or(ks[0]!=m[ks[0]],
                 ks[1]!=m[ks[1]],
                 ks[2]!=m[ks[2]],
                 ks[3]!=m[ks[3]],
                 ks[4]!=m[ks[4]],
                 ks[5]!=m[ks[5]],
                 ks[6]!=m[ks[6]],
                 ks[7]!=m[ks[7]],
                 ks[8]!=m[ks[8]],
                 ks[9]!=m[ks[9]],
                 ks[10]!=m[ks[10]],
                 ks[11]!=m[ks[11]],
                 ks[12]!=m[ks[12]],
                 ks[13]!=m[ks[13]],
                 ks[14]!=m[ks[14]],
                 ks[15]!=m[ks[15]]))


    print("Exhausted all options")
    key = []
    for k in ks:
        key.append(chr(int(str(m[k]))))
    print("".join(key))


if __name__ == "__main__":
    main()
