        vector<vi> acu_mat(N, vi(N));

        int num;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> num;
                if(i == 0 && j == 0){
                    acu_mat[i][j] = num;
                }else if(i == 0){
                    acu_mat[i][j] = num + acu_mat[i][j-1];
                }else if(j == 0){
                    acu_mat[i][j] = num + acu_mat[i-1][j];
                }else{
                    acu_mat[i][j] = num + acu_mat[i][j-1] + acu_mat[i-1][j] - acu_mat[i-1][j-1];
                }
            }
        }

        int maxi = numeric_limits<int>::min();

        for (int i_0 = 0; i_0 < N; ++i_0) {
            for (int j_0 = 0; j_0 < N; ++j_0) {
                for (int i_f = i_0; i_f < N; ++i_f) {
                    for (int j_f = j_0; j_f < N; ++j_f) {

                        int curr_val = acu_mat[i_f][j_f];

                        if(j_0 > 0) curr_val -= acu_mat[i_f][j_0-1];
                        if(i_0 > 0) curr_val -= acu_mat[i_0-1][j_f];
                        if(j_0 > 0 && i_0 > 0) curr_val += acu_mat[i_0-1][j_0-1];

                        maxi = max(maxi, curr_val);
                    }
                }
            }
        }

        cout << maxi << endl;

    }

