letras=[]
while(True):
    try:
        letras += input().split()
    except EOFError:
        break
i =0
lista=[]
while(i<len(letras)):
    j=0
    while(j<len(letras)):
        if(i==j):
            j+=1
            continue
        if(letras[i]+letras[j] not in lista):
            lista.append(letras[i]+letras[j])
        j+=1
    i+=1

lista.sort()
i=0
while(i<len(lista)):
    print(lista[i])
    i+=1