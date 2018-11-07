import os
import getpass
import zipfile
import time

days = ['LUNES', 'MARTES', 'MIERCOLES', 'JUEVES', 'VIERNES']

def getFileName():
	day = int(time.strftime('%w'))
	week = int(time.strftime('%U'))

	return 'RESP{}{}.zip'.format(days[day - 1], week)

def main():
	filename = getFileName()

	print('Ingresar directorio a comprimir:')
	directorio = input()
	resp_zip = zipfile.ZipFile('/home/{0}/Escritorio/{1}'.format(getpass.getuser(), filename), 'w')	
	print('\nComprimiendo archivos...\n')

	for folder, subfolders, files in os.walk(directorio):
		for file in files:
			print(os.path.join(folder, file))

			resp_zip.write(
				os.path.join(folder, file),
				os.path.relpath(os.path.join(folder,file), directorio), 
				compress_type = zipfile.ZIP_DEFLATED
			)

	print('\nArchivo {} generado exitosamente! :)\n'.format(filename))

	resp_zip.close()
 
if __name__ == '__main__':
	main()
