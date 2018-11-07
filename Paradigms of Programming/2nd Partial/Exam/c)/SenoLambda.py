import math
import random

def getRandomArray(n):
	l = [i for i in range(1, n + 1)]

	for i in range(n):
		a = random.randint(0, n - 1)
		b = random.randint(0, n - 1)
		l[a], l[b] = l[b], l[a]

	return l

def main():
	lista = getRandomArray(100)
	listaSenos = list(map(math.sin, lista))
	listaFiltrada = list(filter(lambda x: x > 0.5, listaSenos))
	print(*listaFiltrada)

if __name__ == '__main__':
	main()
