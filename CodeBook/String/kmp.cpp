/*
	Funcionamento do preprocess_lps:

Para melhor compreender o funcionamento veja a foto (pic1) em anexo a essa pasta.
Basicamente os dois intervalos em azul dizem respeito ao maior prefixo&sufixo do subproblema
anterior, i.e, do vetor no intervalo [0.. i - 1]. Agora a pergunta que o algoritmo deve fazer
é: "Será que eu posso expandir esses dois intervalos (em azul) para a direita adicionando o
novo elemento (*i)?" Para isso basta verificar se a direita de ambos intervalos coincidem, i.e., se pat[i] == pat[len].
	Caso pat[i] != pat[len], então não podemos simplesmente extender nosso prefixo&sufixo. Temos que recuar para o segundo maior prefixo&sufixo do nosso subproblema. Para isso uma abordagem ingenua seria simplesmente fazer len = len - 1 e recomecar o loop (pois assim diminuimos em 1 o tamanho do nosso prefixo&sufixo, descobrindo o segundo maior). Contudo, nem sempre existe um prefixo&sufixo que tenha exatamente 1 a menos de tamanho. 
		Exemplo: ABAB		
		Aqui vemos que AB é o prefixo&sufixo mas depois dele não temos nenhum com tamanho 1.
Por isso, utilizamos a linha len = lps[len - 1], pois se existir um sufixo de tamanho len - 1, entao lps[len - 1] = len - 1. Caso contrário, ele nos dará o maior prefixo&sufixo menor que esse tamanho.
			

*/

void preprocess_lps(const char *pat, int M, int *lps) {
    int len = 0;

    lps[0] = 0;

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else  {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Printa os indices no txt onde o pat foi encontrado
void KMP(const char *pat, const char *txt) {
    int M = strlen(pat);
    int N = strlen(txt);

    int lps[M];
    preprocess_lps(pat, M, lps);

    int i = 0;
    int j  = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("%d\n", i-j);
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
