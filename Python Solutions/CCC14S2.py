//Problem Name: Bridge Transport
//Problem description can be found at https://wcipeg.com/problem/ccc13s2

n=input()
z=[input() for i in range(input())]
passerby=[]
o=0
for i in z:
    passerby.append(i)
    if len(passerby)<4:
        if sum(passerby)>n:
            o=1
            break
    elif len(passerby)>=4:
        if sum([passerby[len(passerby)-1],passerby[len(passerby)-2],passerby[len(passerby)-3],passerby[len(passerby)-4]])>n:
            o=1
            break
if len(passerby)==len(z) and o!=1:
    print len(passerby)
else:
    print len(passerby)-1
