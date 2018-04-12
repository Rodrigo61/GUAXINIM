#include <iostream>
#include <vector>

using namespace std;

long long swap_count = 0;
vector<int> vet;

void merge_sort(int left_beg, int left_end, int right_beg, int right_end){

    if(left_end-left_beg == 1){
        if(vet[left_beg] > vet[left_end]){
            swap(vet[left_beg], vet[left_end]);
            swap_count += 1;
        }
    }

    if(right_end-right_beg == 1){
        if(vet[right_beg] > vet[right_end]){
            swap(vet[right_beg], vet[right_end]);
            swap_count += 1;
        }

    }

    if(left_end-left_beg > 1){
        merge_sort(left_beg, ((left_beg+left_end)/2), ((left_beg+left_end)/2)+1, left_end);
    }
    if(right_end-right_beg > 1){
        merge_sort(right_beg, ((right_beg+right_end)/2), ((right_beg+right_end)/2)+1, right_end);
    }

    int left_index = left_beg;
    int right_index = right_beg;
    vector<int> aux;
    while(left_index <= left_end && right_index <= right_end){
        if(vet[left_index] < vet[right_index]){

            aux.push_back(vet[left_index]);
            ++left_index;
        }else{
            aux.push_back(vet[right_index]);
            swap_count += (left_end-left_beg + 1) - (left_index - left_beg);
            ++right_index;
        }
    }

    while(left_index <= left_end){
        aux.push_back(vet[left_index]);
        ++left_index;
    }

    while(right_index <= right_end){
        aux.push_back(vet[right_index]);
        ++right_index;
    }

    for(int i = left_beg, j = 0; i <= right_end; ++i, ++j){
        vet[i] = aux[j];
    }

}

int main() {

    int nSize;

    while(scanf("%d", &nSize) != EOF){

        vet.resize(nSize);

        int n;
        for(int i = 0; i < nSize; ++i){
            scanf("%d", &n);
            vet[i] = n;
        }

        swap_count = 0;
        merge_sort(0, nSize/2, (nSize/2)+1, nSize-1);

        cout << swap_count << endl;

    }

    return 0;
}