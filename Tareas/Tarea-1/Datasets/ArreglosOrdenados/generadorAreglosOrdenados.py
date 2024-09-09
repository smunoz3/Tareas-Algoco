def escribir_arreglo_en_txt(N, filename):
    arreglo = list(range(N))

    with open(filename, 'w') as f:
        f.write(f"{N}\n")
        f.write(" ".join(map(str, arreglo)))


largo = input("Ingrese el largo del arreglo: ")
nombre_archivo = 'arregloOrdenado'+largo+'.txt'
escribir_arreglo_en_txt(int(largo), nombre_archivo)
