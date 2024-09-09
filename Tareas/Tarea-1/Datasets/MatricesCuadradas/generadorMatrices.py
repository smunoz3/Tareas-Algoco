import random

def generar_matriz(N):
    return [[random.randint(0, 9) for _ in range(N)] for _ in range(N)]

def escribir_matrices_en_txt(N, filename):
    matriz1 = generar_matriz(N)
    matriz2 = generar_matriz(N)
    
    with open(filename, 'w') as f:
        f.write(f"{N}\n") 

        for fila in matriz1:
            f.write(" ".join(map(str, fila)) + "\n")
        
        f.write("\n")

        for fila in matriz2:
            f.write(" ".join(map(str, fila)) + "\n")

largo = input("Ingrese el largo de las matrices: ")
filename = 'matrizCuadrada'+largo+'.txt'
escribir_matrices_en_txt(int(largo), filename)
