import os

while 1:
        os.system('./generator > gen')
        os.system('./f < gen > out_alt')
        os.system('./f_alt < gen > out')
        if open('out_alt').read() != open('out').read():
                print('WA')
                exit(0)
