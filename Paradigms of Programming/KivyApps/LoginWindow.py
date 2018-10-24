from kivy.core.window import Window
from kivy.app import App
from kivy.uix.floatlayout import FloatLayout
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.label import Label
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button
from kivy.uix.popup import Popup

class LoginWindow(App):
	global Window

	def __init__(self):
		super(LoginWindow, self).__init__()
		self.isLogged = False

	def build(self):
		# Configuramos la ventana actual
		Window.clearcolor = (.2, .2, .5, 1)
		Window.size = (320, 360)
	
		self.title = 'Iniciar Sesión'

		# Creamos el Widget Raíz
		self.rootWidget = FloatLayout()

		# Creamos el Layout Principal
		self.mainLayout = BoxLayout(orientation='vertical', spacing=30, padding=30)

		# Creamos los Widgets que contendrá
		self.LabelEmail = Label(text='Correo electrónico: ', size_hint=(1, .2), font_size=16)
		self.InputEmail = TextInput(size_hint=(1, .6), multiline=False, font_size=16, padding_y=[12, 12])
		self.LabelPassword = Label(text='Contraseña: ', size_hint=(1, .2), font_size=16)
		self.InputPassword = TextInput(password=True, multiline=False, size_hint=(1, .6), font_size=16, padding_y=[12, 12])
		self.ButtonLogin = Button(text='Iniciar Sesión', size_hint=(1, .8), background_normal='', background_color=[1,1,1,.2])

		# Enlace de eventos a los Widgets
		self.ButtonLogin.bind(on_press=self.submitLogin)

		# Agregamos los Widgets al Layout Principal
		self.mainLayout.add_widget(self.LabelEmail)
		self.mainLayout.add_widget(self.InputEmail)
		self.mainLayout.add_widget(self.LabelPassword)
		self.mainLayout.add_widget(self.InputPassword)
		self.mainLayout.add_widget(self.ButtonLogin)
		self.rootWidget.add_widget(self.mainLayout)

		return self.rootWidget
		
	def submitLogin(self, element_id):
		if not self.isLogged and self.authenticate():
			PopupLoginSuccessful = Popup(
				title='Inicio de sesión exitoso',
				content=Label(text='El usuario ha ingresado exitosamente! :)', font_size=15),
				size_hint=(None, None),
				size=(310, 180)
			)

			PopupLoginSuccessful.open()
			self.isLogged = True
			self.rootWidget.clear_widgets()
		else:
			PopupLoginFailed = Popup(
				title='Inicio de sesión fallido',
				content=Label(text='Correo y/o contraseña incorrectos! :(', font_size=15),
				size_hint=(None, None),
				size=(310, 180)
			)

			PopupLoginFailed.open()

	def authenticate(self):
		email = self.InputEmail.text.strip()
		password = self.InputPassword.text.strip()

		return email == 'mikebsg01@gmail.com' and password == 'hola123'

if __name__ == '__main__':
	LoginWindow().run()
