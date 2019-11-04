import os

while 1:
        os.system('./generator > gen')
        os.system('./b_alt < gen > out_alt')
        os.system('./b < gen > out')
        if open('out_alt').read() != open('out').read():
                print('WA')
                exit(0)
