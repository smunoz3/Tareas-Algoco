largo = int(input())

alturas = input()
alturas=alturas.strip().split()
max=0
max2=0
min=10000000001
i =0
diff=0

while(i<largo):
    if(int(alturas[i])>max):
        if((int(max)-min)>diff):
            diff=int(max)-min
        max=int(alturas[i])
        max2=0
        min=10000000001
    elif(int(alturas[i])>max2):
        if((max2<min)and (max2 !=0)):
           min=max2
        max2=int(alturas[i])
    elif(int(alturas[i])<min):
        min=int(alturas[i])
    i+=1
if((max2-min)>diff):
    diff=int(max2)-min
print(diff)