#include <iostream>
#include <ctime>
int main(int argc, char ** argv){
    srand(time(NULL));
    for(int i=1; i<=10;i++){
        std::cout << "Numero " << i <<": " << rand()%19 + 2 << std::endl;
    }
    return 0;
}
