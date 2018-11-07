from kivy.core.window import Window
from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.label import Label
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button
import random

kivyrgba = lambda r, g, b, a: list(map(lambda x: x / 256, [r, g, b])) + [a]

def conjugar(verbo: str):
	conjugacion = [
		'Yo {}é',
		'Tu {}ás',
		'El {}á',
		'Nosotros {}emos',
		'Ustedes {}án',
		'Ellos {}án'
	]

	for i in range(len(conjugacion)):
		conjugacion[i] = conjugacion[i].format(verbo) + '\n'

	for i in range(len(conjugacion)):
		a = random.randint(0, len(conjugacion) - 1)
		b = random.randint(0, len(conjugacion) - 1)
		conjugacion[a], conjugacion[b] = conjugacion[b], conjugacion[a]

	return conjugacion

class VerboWindow(App):
	global window

	def __init__(self):
		super(VerboWindow, self).__init__()
		self.initialsize = (320, 340)
		self.LabelResponse = None
	
	def build(self):
		Window.clearcolor = tuple(kivyrgba(250, 250, 250, 1))
		Window.size = self.initialsize
		self.title = 'Conjugacion de verbos en futuro'

		self.MainLayout = BoxLayout(orientation='vertical', spacing=30, padding=30)
		self.LabelVerb = Label(text='Inserte un verbo: ', size_hint=(1, .2), font_size=18, color=kivyrgba(0, 0, 0, 1))
		self.InputVerb = TextInput(size_hint=(1, .4), multiline=False, font_size=16, padding_y=[12, 12])
		self.ButtonVerb = Button(text='Convert', size_hint=(1, .4), background_normal='', background_color=kivyrgba(61, 145, 12, 1))
		self.ButtonVerb.bind(on_press=self.mostrarConjugacion)

		self.MainLayout.add_widget(self.LabelVerb)
		self.MainLayout.add_widget(self.InputVerb)
		self.MainLayout.add_widget(self.ButtonVerb)

		return self.MainLayout

	def mostrarConjugacion(self, element_id):
		verbo = self.InputVerb.text.strip()
		l = conjugar(verbo)

		if not self.LabelResponse:
			self.LabelResponse = TextInput(size_hint=(1, 1), font_size=16, padding_y=[12, 12], readonly=True)
			Window.size = tuple([self.initialsize[0], self.initialsize[1] + 180])
			self.MainLayout.add_widget(self.LabelResponse)

		self.LabelResponse.text = ''

		for i in l:
			self.LabelResponse.text += i

def main():
	VerboWindow().run()

if __name__ == '__main__':
	main()
