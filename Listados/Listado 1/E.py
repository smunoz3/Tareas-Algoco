def realizarCompra():
    return 0

def realizarVenta():
    return 0


bloque = int(input())
buy={}
sell={}

a='-'
b='-'
s='-'

while(bloque>0):
    numero=int(input())
    while(numero>0):
        operacion=input()
        operacion=operacion.split(" ")
        if(operacion[0]=='buy'):
            temp=realizarCompra(int(operacion[4]),int(operacion[1]))
            if(not temp):
                buy[operacion[4]]=int(operacion[1])

        else:
            temp=realizarVenta(int(operacion[4]),int(operacion[1]))
            if(not temp):
                buy[operacion[4]]=int(operacion[1])
                
        print(a+b+s)
        numero-=1
    buy.clear()
    sell.clear()
    bloque-=1