#Pattern Generator
#Found at https://www.cemc.uwaterloo.ca/contests/computing/1996/stage1/c-prob.html

import itertools
n=input()
for i in range(n):
    a=map(int, raw_input().split(' '))
    z=[]
    if a[0]==30:
        print 'The bit patterns are'
        o=['1']+['0' for i in range(29)]
        for i in range(0,len(o)):
            print ''.join(o)
            if i!=len(o)-1:
                o[i+1]='1'
                o[i]='0'
    else:
        for q in xrange(a[1]):
            z.append('1')
        for q in xrange(a[0]-a[1]):
            z.append('0')
        p=sorted(list(set(list(itertools.permutations(z)))))
        print ('The bit patterns are')
        for t in reversed(p):
            print ''.join(t)
