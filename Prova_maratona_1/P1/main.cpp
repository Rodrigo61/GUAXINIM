#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int maxi(vector<int> template_music, vector< vector< int > > score, int tam_mus, int qtas_notas){

    vector< vector< int > > dp(tam_mus+1, vector<int>(qtas_notas+1));

    /*Colocando todas as notas contantes na matriz*/

    for (int i = 1; i <= tam_mus; ++i) {
            for (int j = 1; j <= qtas_notas; ++j) {
                if(template_music[i] >= 0){
                    if(template_music[i] == j){
                        dp[i][j] = 0;
                    }else{
                        dp[i][j] = -2;
                    }
                }else{
                    dp[i][j] = -1;
                }

            }
    }

    /*Inicializando caso base*/
    for (int j = 1; j <= qtas_notas; ++j) {
        if(dp[tam_mus][j] != -2)
            dp[tam_mus][j] = 0;
    }

/*    cout << "Init DP:" << endl;
    for (int i = 1; i <= tam_mus; ++i) {
        for (int j = 1; j <= qtas_notas; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/


    for (int i = tam_mus-1; i >= 0; --i) {
        for (int j = 1; j <= qtas_notas; ++j) {

            if(dp[i][j] != -2){
                if(template_music[i+1] < 0){
                    for (int k = 1; k <= qtas_notas; ++k) {
                        dp[i][j] = max(dp[i][j], dp[i+1][k] + score[j][k]);
                    }
                }else{
                    int k = template_music[i+1];
                   /* printf("i = %d, j = %d, k = %d, score = %d\n", i,j,k,score[j][k]);*/
                    dp[i][j] = dp[i+1][k] + score[j][k];
                }
            }
        }
    }

    /*cout << "End DP:" << endl;
    for (int i = 1; i <= tam_mus; ++i) {
        for (int j = 1; j <= qtas_notas; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    return *max_element(dp[1].begin(), dp[1].end());

}

int main() {

    int T;
    int tam_mus, qtas_notas;

    cin >> T;

    for (int w = 0; w < T; ++w) {
        cin >> tam_mus >> qtas_notas;
        vector< vector< int > > score(qtas_notas+1, vector<int>(qtas_notas+1));

        /*cout << "Score:" << endl;*/
        for (int i = 1; i <= qtas_notas; ++i) {
            for (int j = 1; j <= qtas_notas; ++j) {
                cin >> score[i][j];
                /*cout << score[i][j] << " ";*/
            }
            /*cout << endl;*/
        }


        
        vector<int> template_music(tam_mus+1);

        /*cout << "template music: ";*/
        for (int i = 1; i <= tam_mus; ++i) {
            cin >> template_music[i];
            /*cout << template_music[i] << " ";*/
        }
        /*cout << endl;*/

        cout << maxi(template_music, score, tam_mus, qtas_notas) << endl;

    }





    return 0;
}