entrada = input()
ninos, throw = entrada.split()
ninos=int(ninos)
throw=int(throw)

curr=0
i=0
temp=0
stack=[]

entrada=input()
entrada=entrada.strip().split()

while(throw>0):
    if(entrada[i] == 'undo'):
        i+=1
        temp=int(entrada[i])
        while(temp>0):
            stack.pop()
            temp-=1
        curr=stack[-1]
    else:
        temp=int(entrada[i])
        if(temp>=0):
            curr+=temp
            curr=curr%ninos
        else:
            temp=((int(entrada[i])*-1)%ninos)
            curr-=temp
            if(curr<0):
                curr+=ninos
        stack.append(curr)
    i+=1
    throw-=1
print(curr)
