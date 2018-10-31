class Camera():
	def __init__(self):
		print('> Camera initialized.')

	def take_photo(self):
		print('> The %s has taken a photo!' %(type(self).__name__))

	def record_video(self):
		print('> The %s is recording a video...' %(type(self).__name__))
		print('> The %s has recorded a video!' %(type(self).__name__))

class MP3Player():
	def __init__(self):
		print('> MP3Player initialized.')

	def play(self):
		print('> The %s is playing a song...' %(type(self).__name__))

	def stop(self):
		print('> The %s has been stopped!' %(type(self).__name__))

	def forward(self):
		print('> The %s is advancing the song...' %(type(self).__name__))
		print('> The %s has advanced the song!' %(type(self).__name__))

	def backward(self):
		print('> The %s is backing down the song...' %(type(self).__name__))
		print('> The %s has backed down the song!' %(type(self).__name__))

class Person():
	def __init__(self, name: str, phone_number: str):
		self.__name = name
		self.__phone_number = phone_number

	@property
	def name(self):
		return self.__name

	@property
	def phone_number(self):
		return self.__phone_number

class Phone():
	def __init__(self):
		print('> Phone initialized.')

	def call(self, person: Person):
		print('> The %s is calling to %s (%s)...' %(type(self).__name__, person.name, person.phone_number))

	def hang_up(self):
		print('> The %s has been hung!' %(type(self).__name__))

class Cellphone(Camera, MP3Player, Phone):
	def __init__(self):
		print('> Initializing Cellphone:\n')
		print(end='\t>')
		Camera.__init__(self)
		print(end='\t>')
		MP3Player.__init__(self)
		print(end='\t>')
		Phone.__init__(self)
		print('\n> Cellphone initialized.\n')

def main():
	c = Camera()
	c.take_photo()
	c.record_video()
	print()

	mp3 = MP3Player()
	mp3.play()
	mp3.stop()
	mp3.forward()
	mp3.backward()
	print()

	michael = Person('Michael Serrato', '+1-202-555-0113')
	
	phone = Phone()
	phone.call(michael)
	phone.hang_up()
	print()

	cellphone = Cellphone()
	cellphone.take_photo()
	cellphone.play()
	cellphone.call(michael)

if __name__ == '__main__':
	main()
