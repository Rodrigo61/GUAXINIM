import os

while 1:
        os.system('./generator > gen')
        os.system('./main_alt < gen > out_alt')
        os.system('./main < gen > out')
        if open('out_alt').read() != open('out').read():
                print 'WA'
                exit(0)
