#include <iostream>
#include <vector>
#include <algorithm>

void PrintExpressions(const std::vector<std::string>& expressions){
    for(const std::string& exp : expressions){
        std::cout << " # " << exp << std::endl;
    }
    std::cout << std::endl << std::endl;
}

int main(int argc, char ** argv){

    std::vector<std::string> expresiones = {"zapata, si no la gana la empata", "pan comido", "estoy hasta las manos", "es una banda", "cortito y al pie" };

    std::cout << "Expresiones sin ordenar:\n\n";

    PrintExpressions(expresiones);

    std::sort(expresiones.begin(),expresiones.end());

    std::cout << "Expresiones ordenadas:\n\n";

    PrintExpressions(expresiones);

    return 0;
}
