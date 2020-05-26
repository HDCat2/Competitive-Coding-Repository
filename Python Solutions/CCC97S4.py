#Problem Name: Dynamic Dictionary Coding
#Found at https://www.cemc.uwaterloo.ca/contests/computing/1997/stage1/1997CCCStage1Contest.pdf

n=input()
for _ in range(n):
    diction=[]
    words=[]
    while True:
        a=raw_input()
        if a=='':
            break
        else:
            words.append(a.split(' '))
    for q in range(len(words)):
        for i in range(len(words[q])):
            if words[q][i] not in diction:
                diction.append(words[q][i])
            else:
                words[q][i]=str(diction.index(words[q][i])+1)
        print ' '.join(words[q])
