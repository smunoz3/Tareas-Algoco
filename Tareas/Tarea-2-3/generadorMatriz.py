import random

nombre=input("Ingrese el nombre del archivo ")
n = 26
nombre= nombre+".txt"

with open(nombre, "w") as archivo:
    for i in range(n):
        fila = []
        for j in range(n):
            if i == j:
                fila.append(0)
            else:
                fila.append(random.randint(0, 99))

        archivo.write(" ".join(map(str, fila)) + "\n")

print("Archivo "+ nombre +" generado con éxito.")
