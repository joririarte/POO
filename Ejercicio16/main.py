from fastapi import FastAPI
from pymongo import MongoClient

app = FastAPI()

# Conexión a la base de datos MongoDB
client = MongoClient("mongodb://localhost:27017")
db = client["mi_base_de_datos"]
collection = db["mi_coleccion"]

@app.post("/insertar")
def insertar_dato(dato: dict):
    collection.insert_one(dato)
    return {"message": "Dato insertado correctamente"}

@app.get("/consultar/nombre={nombre}")
def consultar_dato(nombre: str):
    dato = collection.find_one({"nombre":nombre},{"_id":0})
    return dato

@app.post("/consultar/usuario={usuario}&clave={clave}")
def validar_usuario(usuario: str, clave: str):
    dato = collection.find_one({"usuario":usuario,"clave":clave},{"_id":0})
    if dato:
        return dato["nombre"] + "::" + dato["apellido"]
    return "denegado"

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="127.0.0.1", port=8000)
