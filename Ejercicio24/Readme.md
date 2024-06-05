# Ejercicio 24

## Enunciado
* Crear un parser que pueda analizar cualquier html en busca de todas las URLs que encuentre
* Crear una GUI que permita al usuario ingresar un sitio web en un QLineEdit
* Que descargue en archivos todos los recursos de dicho sitio web
* Es decir, que busque en el html las imágenes, los css, los javascript y los descargue en archivos
* Que le permita al usuario indicar en qué directorio descargar los archivos
* También agregar un botón que upermita elegir un archivo de imagen del disco con QFileDialog y que la dibuje en pantalla con paintEvent.

## Resolución
* Se modularizó el código utilizando clases separadas
  * Downloader: descarga recursos de internet, implementa una cola de descargas.
  * HtmlFetcher: obtiene un html de un url
  * Parser: obtiene los recursos de un html en una tabla con links y tipo
* La interfaz grafica contiene:
  * Un input de texto para la url
  * Un botón que permite seleccionar el directorio para guardar los recursos de internet e iniciar la descarga
  * una barra de progreso que indica la descarga actual
  * labels que indican el recurso que se descarga y el progreso global de la descarga.
