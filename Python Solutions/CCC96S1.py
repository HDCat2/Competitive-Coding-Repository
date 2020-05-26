#Deficient, Perfect, and Abundant
#Found at https://www.cemc.uwaterloo.ca/contests/computing/1996/stage1/a-prob.html

n=input()
for i in range(n):
    a=input()
    s=sum([n for n in range(1,a) if a%n==0])
    if s == a:
        print "%i is a perfect number." % (a)
    elif s > a:
        print '%i is an abundant number.' % (a)
    else:
        print '%i is a deficient number.' % (a)
