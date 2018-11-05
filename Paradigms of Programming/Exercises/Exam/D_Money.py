def toCurrency(amount):
	amount = float(amount)

	currency = {
		'bills': [1000, 500, 200, 100, 50, 20],
		'coins': [10, 5, 2, 1, 0.5]
	}

	conversion = {
		'bills': [],
		'coins': []
	}

	for currencytype in currency:
		for value in currency[currencytype]:
			quantity = 0

			if amount >= value:
				quantity = int(amount / value)
				amount -= quantity * value

				conversion[currencytype].append({
					'quantity': quantity,
					'value': value
				})

	return conversion

def displayConversion(conversion):
	text = 'Conversion:\n'

	for currencytype in conversion:
		if (len(conversion[currencytype]) > 0):
			text += '\n> %s:\n' %(currencytype.capitalize())

			for change in conversion[currencytype]:
				text += '${:5} (x{})\n'.format(change['value'], change['quantity'])

	return text

from kivy.core.window import Window
from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.label import Label
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button

kivyrgba = lambda r, g, b, a: list(map(lambda x: x / 256, [r, g, b])) + [a]

class CurrencyWindow(App):
	global window

	def __init__(self):
		super(CurrencyWindow, self).__init__()
		self.initialsize = (320, 340)
		self.LabelResponse = None

	def build(self):
		Window.clearcolor = tuple(kivyrgba(240, 240, 240, 1))
		Window.size = self.initialsize
		self.title = 'Conversion to Currency'

		self.MainLayout = BoxLayout(orientation='vertical', spacing=30, padding=30)
		self.LabelAmount = Label(text='Insert the amount ($): ', size_hint=(1, .2), font_size=18, color=kivyrgba(1, 145, 12, 1))
		self.InputAmount = TextInput(size_hint=(1, .6), multiline=False, font_size=16, padding_y=[12, 12])
		self.ButtonConvert = Button(text='Convert', size_hint=(1, .8), background_normal='', background_color=kivyrgba(61, 145, 12, 1))
		self.ButtonClear = Button(text='Clear', size_hint=(1, .8), background_normal='', background_color=kivyrgba(6, 192, 249, 1))

		self.ButtonConvert.bind(on_press=self.convertAmountToCurrency)
		self.ButtonClear.bind(on_press=self.clearResponse)

		self.MainLayout.add_widget(self.LabelAmount)
		self.MainLayout.add_widget(self.InputAmount)
		self.MainLayout.add_widget(self.ButtonConvert)
		self.MainLayout.add_widget(self.ButtonClear)
		
		return self.MainLayout

	def convertAmountToCurrency(self, element_id):
		if not self.LabelResponse:
			self.LabelResponse = TextInput(text='', readonly=True, size_hint=(1, 2))
			Window.size = tuple([self.initialsize[0], self.initialsize[1] + 180])
			self.MainLayout.add_widget(self.LabelResponse)
		
		amount = self.InputAmount.text.strip()

		try:
			conversion = toCurrency(amount)
			response = displayConversion(conversion)
			self.LabelResponse.text = response
		except:
			self.LabelResponse.text = 'Incorrect Value: The value must be a decimal number.'

	def clearResponse(self, element_id):
		if self.LabelResponse:
			self.MainLayout.remove_widget(self.LabelResponse)
			self.LabelResponse = None
			Window.size = self.initialsize

def main():
	CurrencyWindow().run()
	

if __name__ == '__main__':
	main()				
