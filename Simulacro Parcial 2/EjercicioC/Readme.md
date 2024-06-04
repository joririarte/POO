# Ejercicio C

## Enunciado
* Usar la clase Manager para gestionar todas las ventanas de una nueva aplicación.
* Usar un login (clase Login) que valide usuarios contra la tabla usuarios usando AdminDB.
* Para el campo clave usar MD5.
* La base de datos debe estar en el archivo base.sqlite
* Login y AdminDB que sean singleton.
* Cada clase en sus correspondientes archivos .h y .cpp
* Cuando un usuario ingrese correctamente, mostrar una ventana vacía.

## Resolución
* Se utilizó la clase Manager para la gestión de ventanas.
* Además se utilizó Manager para independizar a Login de la clase AdminDB: 
  * Cuando se presiona el botón para ingresar, Login emite una señal para solicitar una validación.
  * Manager captura la señal y la procesa con AdminDB
  * Validado el usuario, Manager abre la ventana nueva.
  * La ventaja que se produce, es que Login no depende de un método de validación o Base de Datos, ni debe conocer Login qué se usa para validar, sino que esto sucede en otra parte, ajena al login.
