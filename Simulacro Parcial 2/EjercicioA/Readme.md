# Ejercicio A

## Enunciado
* Definir una ventana vacía en la clase Principal, que herede de QWidget y diseñado con QtDesigner.
* Agregar a este proyecto la clase AdminDB para permitir el uso de una base de datos.
* Instanciar un único objeto de AdminDB en la aplicación.
* Definir una clase Linea con las siguientes características:
  * En los archivos fuente linea.h y linea.cpp
  * Atributos privados: int x_inicial, y_inicial, x_final, y_final
  * Con sus getters y setters.
  * Utilizar en esta clase todos los const que son recomendables
* Definir una tabla "lineas" en la base de datos con los siguientes campos: id, x_inicial, y_inicial, x_final, y_final
* Cargar en la base de datos un único registro, es decir, los datos de una única línea.
* Desde la clase Principal se podrá leer este único registro y crear un objeto Linea con esos datos.
* Dibujar con paintEvent esta línea dentro de la ventana con las coordenadas leídas de la base.

## Resolución
* Se creó un projecto con QT Designer con Principal como la primer ventana a mostrarse.
* La clase línea se definió con setters y getters, estos últimos devuelven un QPoint con X e Y.
* La clase AdminDB implementa a la clase Linea, devolviendo un QVector de Linea cuando se realiza la consulta a la base.
* La clase Principal dibuja todas las lineas que devuelve la base de datos.
