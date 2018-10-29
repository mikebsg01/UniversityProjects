fnY = lambda x: 8 + (2 * x) + (x ** 2)

def main():
	x = [5, 12, 23, 34, 56]
	y = map(fnY, x)
	
	print('x: ', end='')
	
	for i in x:
		print('{:4}'.format(i), end=' ')

	print('\ny: ', end='')

	for i in y:
		print('{:4}'.format(i), end=' ')

	print()

if __name__ == '__main__':
	main()
