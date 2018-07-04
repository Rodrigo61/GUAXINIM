n_cases = int(input());

for w in range(0, n_cases):

    target = input();
    source = input()

    N = len(target)
    M = len(source)


    dp = [[0 for x in range(M + 1)] for y in range(N + 1)]

    # print("dp size = ", len(dp))
    # print("dp[0] size = ", len(dp[0]))


    for i in range(0,N):
        if (target[i] == source[M - 1]):
            # print("i = ", i)
            # print("M - 1 = ", M - 1)
            dp[i][M - 1] = 1;

    # for i in range(0, N + 1):
    #     for j in range(0, M + 1):
    #         print(dp[i][j], end=" ")
    #     print("")


    last_col = [0 for x in range(N)]
    last_col[0] = dp[0][M - 1]
    for i in range(1,N):
        last_col[i] = last_col[i - 1] + dp[i][M - 1]


    for j in range(M - 2, -1, -1):
        for i in range(0, N):
            if target[i] == source[j]:
                    dp[i][j] = last_col[N - 1] - last_col[i]

        last_col[0] = dp[0][j]
        for i in range(1, N):
            last_col[i] = last_col[i - 1] + dp[i][j]

    acu = 0;
    for i in range(0, N):
        acu = acu + dp[i][0]


    print(acu)
