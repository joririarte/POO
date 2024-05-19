# Ejercicio 21

## Enunciado
* Definir dos QWidgets (una clase Login y una clase Ventana).
* El Login validará al usuario contra una base SQLite
* La Ventana sólo mostrará un QPushButton para "Volver" al login.
* Crear solamente un objeto de Ventana y uno solo de Login.
* Si sucede un problema en la compilación, analizar los motivos (respetar el enunciado).
* Solucionar ese problema y ver la alternativa de hacerlo con Manager.

## Resolución

### Problema de Compilación
En la carpeta Ejercicio21-ProblemaCompilacion se encuentra el proyecto con el problema de compilación. El problema se debe a una definición circular de las clases donde una implementa a otra y viceversa. Esto genera que ninguna de las dos pueda construirse ya que ninguna de las dos está completa sin la otra.

### Solución con Forward Declaration
En la carpeta Ejercicio21-ForwardDeclaration, se encuentra una solución a este problema utilizando una técnica llamada Forward Declaration. En ésta técnica se basa en realizar "una promesa" al compilador de que una clase existe en el archivo de cabecera. Para el archivo de cabecera la clase que se promete es un tipo incompleto, por lo que debe completarse. El tipo se completa al incluir el archivo de cabecera que contiene el tipo en la definición de la clase, es decir, el archivo cpp.

### Solución con clase Manager
En la carpeta Ejercicio21-Manager se encontrará la solución con una clase Manager.

La clase Manager, una clase personalizada que hereda de QObject, es una clase donde se puede definir el flujo de las ventanas del programa. Utilizarla resulta mucho más conveniente que el uso de Forward Declaration por los siguientes motivos:
* Modularidad: Permite crear simplemente componentes (QWidgets) que no sólo pueden servir para el proyecto actual sino que pueden servir para otro proyecto
* Evita las definiciones circulares y el Forward Declaration: El componente que se crea es independiente de otros con los que se tenga que comunicar, es decir no hace falta que un componente conozca a otro.
* Escalabilidad y Mantenimiento: En la clase manager se concentrarán todas las conexiones que hagan al flujo del programa, lo cual permite que al agregar un componente nuevo simplemente deba ser agregado a la clase manager, y esto a su vez mejora el mantenimiento del software.
