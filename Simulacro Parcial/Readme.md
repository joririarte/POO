# Ejercicio A
- Comenzar un proyecto vacío con QtCreator y diseñar un login de usuarios como el siguiente:


- Tendrá un tamaño de 250x120 píxeles y llevará por título "Login".
- Para el layout utilizar QGridLayout.
- El único usuario válido es el DNI de estudiante y como clave sus últimos 3 números del DNI.
- Ocultar con asteriscos la clave y detectar el Enter para validar al usuario.
- Si el usuario y clave no es válido, sólo el campo de la clave se deberá limpiar.
- Al fallar la clave 3 veces, la aplicación se cierra.
- Si el usuario es válido, entonces se oculta el login y se visualiza un nuevo QWidget como el que sigue:


- Utilizar una imagen del disco aproximadamente de 100x100 píxeles.
- Esta imagen se mostrará en el QWidget exactamente centrada.
- Dibujar además un cuadrado que envuelva la imagen (como muestra el ejemplo).
# Ejercicio D (Galeria de Fotos)

- Diseñar una aplicación para una galería de fotos
- En un archivo .txt almacenar en cada línea, una URL a una imagen
- Un botón >> y otro botón << para avanzar o retroceder en la galería de fotos


 # Ejercicio E (Bola 8)

- Definir la clase Ventana que herede de QWidget
- Usar desde el disco una imagen de una bola 8 con formato PNG (para usar transparencias).
- Ventana tendrá un QGroupBox con los siguientes parámetros:
	- Diámetro de la bola (en píxeles)
	- Velocidad (segundos para ir de lado a lado)
	- QPushButton para actualizar estos parámetros en la bola
- La bola irá golpeando de izquierda a derecha en la Ventana.
