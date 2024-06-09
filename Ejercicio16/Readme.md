# Ejercicio 16

## Primer Enunciado
* Registrar en MongoDB algunos usuarios (nombre, apellido, usuario, clave)
* Tener disponible un endpoint con FastAPI para validar usuarios.

## Segundo Enunciado
* Que el endpoint para validar a los usuarios sea con un POST y que devuelva "denegado" o que devuelva el nombre y el apellido del usuario en el siguiente formato: "Juan Carlos::Ponce"
* Probar el funcionamiento de este endpoint mediante la web de prueba de FastAPI.

## Tercer Enunciado
* Este ejercicio viene de la clase 5 y 7.
* Luego de tener registrados los usuarios en MongoDB y funcionando el endpoint.
* Acondicionar la clase Login para validar los usuarios contra el endpoint de FastAPI.

## Resolución
* En el archivo main.py se encuentra el código python con el que se creó la API con fast API.
* Dentro de la carpeta Ejercicio16 está el proyecto QT que implementa la API, y valida usuarios que estén registrados.
