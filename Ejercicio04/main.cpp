/*
* Ejercicio 04
* De un vector de int pseudo aleatorios busca la moda
* Solo obtiene una moda, no considera distribuciones bimodales o multimodales.
*/
#include <iostream>
#include <vector>
#include <ctime>
#include <unordered_map>

//Obtiene la moda de un vector de int
//Devuelve la moda y un mapa de frecuencias
int findMode(const std::vector<int>& nums, std::unordered_map<int,int>& outFreq){

    //Crea el mapa de numeros y sus frecuencias
    for(int num : nums){
        outFreq[num]++;
    }

    int mode = 0;
    int max = 0;
    //Busca la frecuencia maxima
    for(const auto& pair : outFreq){
        if(pair.second > max){
            max = pair.second;
            mode = pair.first;
        }
    }

    return mode;
}

//imprime el map por consola
void printMap(const std::unordered_map<int,int>& freq){
    for(const auto& pair : freq){
        std::cout << "Num: "<< pair.first <<
                     " Freq: " << pair.second << std::endl;
    }
}
int main(int argc, char** argv){

    //creacion del vector con numeros aleatorios
    std::vector<int> numeros;
    srand(time(NULL));

    for(int i=0; i<30; i++){
        numeros.push_back( rand()%15 +1 );
    }

    //impresion por pantalla del vector
    std::cout << "El vector es:\n";

    for(int num : numeros){
        std::cout << num << std::endl;
    }

    //Busca la moda y crea el mapa de frecuencias.
    std::unordered_map<int,int> frecuencias;

    int mode = findMode(numeros, frecuencias);

    //impresion del mapa
    std::cout << "\nLas frecuencias son:\n";
    printMap(frecuencias);

    //impresion de la moda
    std::cout << "\nLa moda es: " << mode << std::endl;
    return 0;
}
