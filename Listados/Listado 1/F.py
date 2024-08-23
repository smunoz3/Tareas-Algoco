entrada = input()
total, vistas = entrada.split()
total=int(total)
vistas=int(vistas)
i =0
array= []
while(i<vistas):
    entrada = int(input())
    if(entrada not in array):
        array.append(entrada)
    i+=1
i=0
while(i<total):
    if(i not in array):
        print(i)
    i+=1

print("Mario got "+ str(len(array))+ " of the dangerous obstacles.")