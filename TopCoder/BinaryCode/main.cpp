#include <iostream>
#include <vector>

using namespace std;

class BinaryCode{
public:

    vector<string> decode(string message){
        char anterior, atual, proximo;
        vector<string> vetorDecodificado(2);

        //verificando com 0
        anterior = '0';
        atual = '0';
        for(char charAtual : message){
            proximo = charAtual - atual - anterior;
            if(proximo != '0' && proximo != '1'){
                vetorDecodificado[0] = "NONE";
                break;
            }else{
                vetorDecodificado[0]+= atual;
                anterior = atual;
                atual = proximo;
            }
        }

        anterior = '0';
        atual = '1';
        for(char charAtual : message){
            proximo = charAtual - atual - anterior;
            if(proximo != '0' && proximo != '1'){
                vetorDecodificado[1] = "NONE";
                break;
            }else{
                vetorDecodificado[1]+= atual;
                anterior = atual;
                atual = proximo;
            }
        }

        return vetorDecodificado;


    }
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}