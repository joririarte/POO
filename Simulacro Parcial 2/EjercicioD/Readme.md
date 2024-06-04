# Ejercicio D

## Enunciado
* Crear una clase Lienzo que herede de QWidget, creado con QtDesigner y que permita dibujar con paintEvent.
* Cuando se presiona la tecla A (Activar) se comenzará a dibujar cada posición en donde se encuentra el mouse. No depende de que se presione algún bóton del mouse para comenzar a dibujar.
* Cuando se presiona la tecla D (Desactivar) se dejará de dibujar.
* La clase Lienzo recibe una enumeración que puede ser: TrazoFino, TrazoMediano, TrazoGrueso que determinará el grosor de lo que se dibuja.
* Dentro de Lienzo y ubicado abajo a la derecha, se ubicará un objeto de MiLabel, que hereda de QLabel, con una señal propia para detectar el click del mouse.
* Cuando se presione este MiLabel, se borrará todo lo dibujado.

## Resolución
* Se creó una clase Lienzo con QtDesigner que hereda de QWidget, que solo contiene la funcionalidad de dibujo con las teclas A y D, y recibe un enum para cambiar el ancho del trazo.
* Se creó otra clase Paint con QtDesigner que contiene un QWidget promovido a Lienzo. Paint tiene el label para borrar y un combobox para cambiar el trazo
* El label se promovió a una clase MiLabel que hereda de QLabel y que tiene una señal de click, que lo hace funcionar como un botón. 
