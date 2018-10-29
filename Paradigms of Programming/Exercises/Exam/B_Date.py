import time

days = ['Lunes', 'Martes', 'Miércoles', 'Jueves', 'Viernes']

def getDate():
	day = int(time.strftime('%w'))
	week = int(time.strftime('%U'))
	return '{0} {1} {2} {3}'.format(time.strftime('%Y-%m-%d'), days[day - 1], week, day)

print(getDate())
