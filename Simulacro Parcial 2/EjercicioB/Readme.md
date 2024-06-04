# Ejercicio B

## Enunciado
* Definir un formulario en la clase Formulario usando QtDesigner.
* En Formulario se darán de alta instrumentos en un negocio de instrumentos musicales.
* Los instrumentos que se pueden cargar serán: guitarras, vientos y teclados.
* Definir las clases Instrumento, Guitarra, Viento y Teclado.
* Cada clase en sus correspondientes archivos .h y .cpp
* Instrumento será una clase abstracta con la función virtual pura void afinar()
* Que esa función virtual pura simplemente publique un texto por consola, por ejemplo "Afinando guitarra".
* El formulario tendrá un botón que agregará un instrumento nuevo a un QVector< Instrumento * >
* El formulario tendrá un QComboBox en el cual tendrá el siguiente listado: Guitarra, Viento y Teclado.
* El formulario también tendrá un botón "Ver stock" que publicará por consola todos los instrumentos cargados.
* Los Instrumentos tendrán los siguientes atributos: marca, precio, cantidad_de_cuerdas, cantidad_de_teclas, metal_usado.
* Cuando en el QComboBox se seleccione Guitarra, se deberá permitir ingresar sólo la marca, el precio y la cantidad de cuerdas.

## Resolución

* Se implementó la clase Formulario con QT Designer utilizando los Widgets necesarios, y cuidando la presentación con Grid Layout y Horizontal Layout
* Se definió la jerarquía de instrumentos comenzando con la clase Instrumento (abstracta) de la que heredan al mismo nivel Guitarra, Teclado y Viento
* El formulario responde a la selección del ComboBox cambiando el texto del último label para indicar al usuario qué es lo que se debe ingresar en ese campo, teniendo en cuenta que ese campo es propio de las clases derivadas de Instrumento. 
* Además de los atributos requeridos, se añadió un atributo tipo, el cual indica con un QString qué instrumento es.
* La salida publicada por consola de los instrumentos en el vector visualizan el tipo, la marca, el precio y el atributo de cuerdas, teclas o metal según corresponda.
* se utilizó el método static_cast< TIPO >( VARIABLE ) para obtener de cada entrada del vector el tipo correspondiente.
