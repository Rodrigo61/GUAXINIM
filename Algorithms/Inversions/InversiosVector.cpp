/*
	Aqui eu calculo o numero de inversoes durante o merge sort. Essa funcao realmente
	ordena o vetor, entao tome cuidado para protege-lo.
	ATENCAO: Essa funcao apenas foi testada para numeros distintos, cheque melhor caso
	nao seja o caso.

	Complexidade O(nlgn)
*/

int count_inversions(vi &vet, int begin, int end) {

    if (begin == end) {
        return 0;
    }

    int mid = (begin+end)/2;
    int left_inv  = count_inversions(vet, begin, mid);
    int right_inv = count_inversions(vet, mid + 1, end);

    vi aux_vet;
    int total_inv = left_inv + right_inv;

    int left_pos = begin;
    int right_pos = mid + 1;

    while (left_pos <= (begin+end)/2 && right_pos <= end) {
        if (vet[right_pos] < vet[left_pos]) {
            total_inv += mid - begin + 1 - (left_pos - begin);
            aux_vet.push_back(vet[right_pos]);
            ++right_pos;
        } else {
            aux_vet.push_back(vet[left_pos]);
            ++left_pos;
        }
    }

    while (left_pos <= (begin+end)/2) {
        aux_vet.push_back(vet[left_pos]);
        ++left_pos;
    }

    while (right_pos <= end) {
        aux_vet.push_back(vet[right_pos]);
        ++right_pos;
    }

    for (size_t i = begin; i <= end; i++) {
        vet[i] = aux_vet[i - begin];
    }

    return total_inv;
}
