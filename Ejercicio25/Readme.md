# Ejercicio 25:
## Enunciado
* Construir un nuevo proyecto que tenga un Login independiente, es decir, que no dependa de otra clase GUI.
* El Login tenga un QLabel que funciona como botón que sea para registrar un nuevo usuario.
* Cuando se presiona el QLabel que funciona como botón, se abrirá una ventana para dar de alta un usuario.
* Usar SQLite con AdminDB como singleton.
* Cuando un usuario válido ingresa correctamente se mostrará otra ventana que visualizará todos los usuarios cargados en la base.
* Para la visualización de los usuarios se puede usar QTreeWidget. Agregar la funcionalidad para que en esta misma ventana se puedan editar los campos como si fuera una planilla tipo excel.
* Seguir las recomendaciones que se comentaron durante el dictado de clases para construir las clases.

## Resolucion
* Además del requerimiento de la consigna se añadió
  * En la clase Ventana:
    * un label que indica el usuario actual de la sesión
    * Se esconde la Clave con asteriscos
    * No se permite editar id, nombre de usuario, ni clave con un styledelegate
    * cada vez que se abre Ventana se vuelve a leer la BD de usuarios 
  * Los botones Registrarse de Login y Volver de Ventana emiten una señal que la clase Manager utiliza para volver al Login
