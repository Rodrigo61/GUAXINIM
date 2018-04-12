#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n_app, n_evnt;

    cin >> n_app >> n_evnt;
    n_app++;

    int vet_noti[n_app];
    memset(vet_noti, 0, sizeof(int)*n_app);
    int vet_lazy[n_app];
    memset(vet_lazy, 0, sizeof(int)*n_app);

    vector<int> log_noti;
    log_noti.reserve(n_evnt);
    int log_beg = 0;

    int sum_noti = 0;
    for (int w = 0; w < n_evnt; ++w) {
        int cmd;
        cin >> cmd;

        switch(cmd){
            case 1:{
                int x;
                cin >> x;
                ++vet_noti[x];
                log_noti.push_back(x);
                ++sum_noti;
                break;
            }
            case 2:{
                int x;
                cin >> x;
                sum_noti -= vet_noti[x];
                vet_lazy[x] += vet_noti[x];
                vet_noti[x] = 0;
                break;
            }
            case 3:{
                int t;
                cin >> t;

                for (int i = min(t, log_beg); i < t; ++i) {
                    if(log_noti[i] != 0){
                        if(vet_lazy[log_noti[i]] == 0){
                            --sum_noti;
                            --vet_noti[log_noti[i]];
                            log_noti[i] = 0;
                        }else{
                            log_noti[i] = 0;
                            --vet_lazy[log_noti[i]];
                        }
                    }
                }
                log_beg = max(log_beg, t);
                break;
            }
        }

        cout << sum_noti << endl;
    }


    return 0;
}