import random

nombre=input("Ingrese el nombre del archivo ")
n = 26
nombre= nombre+".txt"

vector = [random.randint(0, 99) for _ in range(n)]

with open(nombre, "w") as archivo:
    archivo.write(" ".join(map(str, vector)) + "\n")

print("Archivo "+ nombre +" generado con éxito.")
