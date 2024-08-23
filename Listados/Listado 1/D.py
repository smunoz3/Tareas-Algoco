import collections

num_operaciones = int(input())
i =0
while(i<num_operaciones):
    opera=input()
    opera=list(opera)
    largo=int(input())
    lista=input()
    lista=lista[1:-1].split(',')
    lista = collections.deque(lista)
    flag_error=True
    flag_direccion=True

    for j in opera:
        if(j=="R"):
            flag_direccion=not flag_direccion
        else:
            if(largo==0):
                flag_error=False
                break
            else:
                largo-=1
                if(flag_direccion):
                    lista.popleft()
                else:
                    lista.pop()

    i+=1
    if(flag_error):
        if(flag_direccion):
            pantalla='['
            for n in lista:
                pantalla=pantalla+n+','
            pantalla=pantalla[:-1]+']'
            print(pantalla)
        else:
            lista.reverse()
            pantalla='['
            for n in lista:
                pantalla=pantalla+n+','
            pantalla=pantalla[:-1]+']'
            print(pantalla)
    else:
        print("error")