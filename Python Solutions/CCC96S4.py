#When in Rome
#Found at https://www.cemc.uwaterloo.ca/contests/computing/1996/stage1/d-prob.html

def int_to_roman (integer):

    returnstring=''
    table=[['M',1000],['CM',900],['D',500],['CD',400],['C',100],['XC',90],['L',50],['XL',40],['X',10],['IX',9],['V',5],['IV',4],['I',1]]

    for pair in table:

        while integer-pair[1]>=0:

            integer-=pair[1]
            returnstring+=pair[0]

    return returnstring

def rom_to_int(string):

    table=[['M',1000],['CM',900],['D',500],['CD',400],['C',100],['XC',90],['L',50],['XL',40],['X',10],['IX',9],['V',5],['IV',4],['I',1]]
    returnint=0
    for pair in table:


        continueyes=True

        while continueyes:
            if len(string)>=len(pair[0]):

                if string[0:len(pair[0])]==pair[0]:
                    returnint+=pair[1]
                    string=string[len(pair[0]):]

                else: continueyes=False
            else: continueyes=False

    return returnint
n=input()
for i in range(n):
    p=raw_input()
    q=p
    p=p.split('+')
    p[1]=list(p[1])
    p[1].remove('=')
    p[1]=''.join(p[1])
    number=rom_to_int(p[0])+rom_to_int(p[1])
    if number>1000:
        number = 'CONCORDIA CUM VERITATE'
    else:
        number=int_to_roman(number)
    print q+number
