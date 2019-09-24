import os

cnt = 0
while 1:
        os.system('./generator > gen')
        os.system('./g_brute < gen > out_alt')
        os.system('./g < gen > out')
        cnt = cnt + 1
        print(cnt)
        if open('out_alt').read() != open('out').read():
                print('WA')
                exit(0)
