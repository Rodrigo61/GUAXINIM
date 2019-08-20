import os

while 1:
        os.system('./generator > gen')
        os.system('./dalt < gen > out_alt')
        os.system('./d < gen > out')
        if open('out_alt').read() != open('out').read():
                print 'WA'
                exit(0)
