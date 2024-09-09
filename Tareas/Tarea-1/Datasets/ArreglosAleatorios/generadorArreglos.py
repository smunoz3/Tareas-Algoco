import random

def escribir_arreglo_en_archivo(largo, nombre_archivo):
    arreglo = [random.randint(0, 99) for _ in range(largo)]
    
    with open(nombre_archivo, 'w') as archivo:
        archivo.write(f"{largo}\n")
        archivo.write(' '.join(map(str, arreglo)) + '\n')


largo = input("Ingrese el largo del arreglo: ")
nombre_archivo = 'arregloAleatorio'+largo+'.txt'
escribir_arreglo_en_archivo(int(largo), nombre_archivo)
