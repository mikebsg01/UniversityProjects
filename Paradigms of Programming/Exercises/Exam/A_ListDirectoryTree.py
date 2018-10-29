import os

for root, dirnames, filenames in os.walk('.'):
	for filename in filenames:
		if filename.endswith('.txt'):
			print(os.path.join(root, filename))
