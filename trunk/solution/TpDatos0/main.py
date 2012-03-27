""" Cosas que hace el script:
- El script debe estar en la carpeta donde se encuentra el tp
- El archivo debe ser tp.c
- Compila el tp en C (ejecuta make en la carpeta donde este)
- Genera "cant" archivos con bytes ASCII aleatorios (con longitudes de 2⁰ a 2¹⁶) "ranIteracion.txt"
- Aplica cada algoritmo de ordenamiento a cada uno (total el ordenamiento se hace en memoria).
- Saca el log del profiler de cada archivo ordenado. "ArchivoDeLog_ordenamiento_iteracion.txt"
- Saca un archivo con el tiempo que tardo en ejecutarse el programa "tiempo_ordenamiento_iteracion.txt"
- Y nos da un archivo ordenado, para poder correr la otra prueba del tp (Cuanto tarda en ordenar algo que ya esta ordenado). """

import os

def cantidad(i):
	return 100 * (2**i)


def generar(cant):
	for i in range(0,cant):
		#print("tr -dc A-Za-z0-9 </dev/urandom |  head -c "+str(cantidad(i))+" > ran"+str(i)+".txt")
		os.system("tr -dc A-Za-z0-9 </dev/urandom |  head -c "+str(cantidad(i))+" > ran"+str(i)+".txt")
		
def ordenar(cant):
	os.system("make")
	
	for i in range(0,cant):
		num = str(i)
		print ("Ronda ",i)
		time = "time -f \"Tiempo Real: %E ,Tiempo Usuario:%U ,Tiempo del CPU: %S\" "
		#print("tr -dc A-Za-z0-9 </dev/urandom |  head -c "+str(cantidad(i))+" > ran"+str(i)+".txt")
		for param in ['s','m']:
			sorted =  "> sorted_"+ param + "_"+ num +".txt"
			saveTime = "-o tiempo_"+param +"_" + num +".txt"
			if (param == 'm'):	
				# Que solo me devuelva el archivo ordenado cuando ordena con mergeSort
				# Tener 2 archivos iguales ordenados es... innecesario.
				os.system(time+saveTime+" ./tp -" + param +" ran" + num + ".txt"+" "+sorted)
			else:
				os.system(time+saveTime+" ./tp -" + param +" ran" + num + ".txt")
			os.system("gprof ./tp > ArchivoDeLog_"+ param + "_" + num +".txt")

def main():
	# Cantidad de iteraciones, las ultimas (de la 13 en adelante) tardan bastante tiempo
	valor = 10
	generar(valor)
	ordenar(valor)

if __name__ == '__main__':
	main()
