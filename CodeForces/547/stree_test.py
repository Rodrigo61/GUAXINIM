import os

while 1:
        os.system('./generator > gen')
        ret = os.system('./d < gen')
        if ret:
                print('WA')
                exit(0)
