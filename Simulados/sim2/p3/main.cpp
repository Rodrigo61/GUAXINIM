#include <cstring>

int verifica_quadrante(int mat[9][9], int x_centro, int y_centro){

}

int solucao(int mat[9][9]){

    int vet_ocorrencia[10];

    // verificando colunas
    memset(vet_ocorrencia, 0, sizeof(int)*10); // inicializando tudo com 0
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            ++vet_ocorrencia[mat[j][i]];

            if(vet_ocorrencia[mat[j][i]] > 1){
                return 0;
            }
        }
    }

    // verificando linhas
    memset(vet_ocorrencia, 0, sizeof(int)*10); // inicializando tudo com 0
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            ++vet_ocorrencia[mat[i][j]];

            if(vet_ocorrencia[mat[i][j]] > 1){
                return 0;
            }
        }
    }

    if(verifica_quadrante(mat, 1, 1) == 0){
        return 0;
    }


}