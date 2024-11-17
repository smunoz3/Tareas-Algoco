import random
import string

# Función para generar una palabra aleatoria de longitud L
def generar_palabra(largo):
    return ''.join(random.choices(string.ascii_lowercase, k=largo))

# Recibir el número de pares de palabras (N) por input
N = int(input("Ingresa el número de pares de palabras: "))

flag = True

# Generar y escribir las palabras en el archivo
with open("palabras.txt", "w") as archivo:
    archivo.write(f"{N}\n")
    N = N * 2
    
    for _ in range(N):
        L = random.randint(0, 30)  
        palabra = generar_palabra(L)
        
        archivo.write(f"{palabra}")
        if flag:
            archivo.write("|")
        else:
            archivo.write("\n")

        flag = not flag

print(f"Las palabras se han generado y guardado en el archivo 'palabras.txt'.")
