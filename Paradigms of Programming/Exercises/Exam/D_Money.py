def toCurrency(amount):
	currency = {
		'bills': [1000, 500, 200, 100, 50, 20],
		'coins': [10, 5, 2, 1, 0.5]
	}

	conversion = {
		'bills': [],
		'coins': []
	}

	while amount > 0:
		for currencytype in currency:
			for value in currency[currencytype]:
				quantity = 0

				while amount >= value:
					amount -= value
					quantity += 1

				if quantity > 0:
					conversion[currencytype].append({
						'quantity': quantity,
						'value': value
					})

	return conversion

def main():
	print('Insert the amount ($): ', end='')
	amount = float(input())
	conversion = toCurrency(amount)
	print('\nConversion: ')

	for currencytype in conversion:
		if (len(conversion[currencytype]) > 0):
			print('\n> %s: ' %(currencytype.capitalize()))

			for change in conversion[currencytype]:
				print('${:5} (x{})'.format(change['value'], change['quantity']))

if __name__ == '__main__':
	main()				
