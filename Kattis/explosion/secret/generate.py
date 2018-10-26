import math
import random

MAX_HEALTH = 6
MIN_MINIONS = 1
MAX_MINIONS = 5
MAX_DAMAGE = 100
MAX_SIDE_HEALTH = MAX_HEALTH * MAX_MINIONS

case_no = 0

def add_case(your_minions, opp_minions, damage, case_name = ''):
    global case_no
    case_no += 1
    file_name = '%02d' % case_no
    if case_name:
        file_name = file_name + '-' + case_name
    file_name += '.in'

    if damage <= 0:
        damage = sum(your_minions) + sum(opp_minions) + damage

    with open(file_name, "wt") as f:
        f.write('%d %d %d\n' % (len(your_minions), len(opp_minions), damage))
        f.write(' '.join(map(lambda x:str(x), your_minions)))
        f.write('\n')
        f.write(' '.join(map(lambda x:str(x), opp_minions)))
        f.write('\n')

def random_health_total(n, health):
    a = [0] * n
    for i in range(int(health)):
        ix = -1
        while ix < 0 or a[ix] == MAX_HEALTH:
            ix = random.randint(0, n - 1)
        a[ix] += 1
    return filter(lambda x:x>0, a)

def main():
    random.seed(0)
    add_case(
        [MAX_HEALTH] * MAX_MINIONS,
        [MAX_HEALTH] * MAX_MINIONS,
        math.floor(MAX_HEALTH * MAX_MINIONS * 2 * 0.95),
        'max')
    add_case(
        random_health_total(MAX_MINIONS, math.floor(MAX_SIDE_HEALTH * 0.8)),
        random_health_total(MAX_MINIONS - 1, math.floor((MAX_MINIONS - 1) * MAX_HEALTH * 0.4)),
        MAX_DAMAGE - 7,
        'all')
    add_case(
        random_health_total(MAX_MINIONS, math.floor(MAX_SIDE_HEALTH * 0.7)),
        random_health_total(MAX_MINIONS - 1, math.floor((MAX_MINIONS - 1) * MAX_HEALTH * 0.5)),
        0,
        'all-exact')
    add_case([1,2], [1,2,3], 5, 'impossible')

    for i in range(5):
        add_case(
            random_health_total(MAX_MINIONS, math.floor(MAX_SIDE_HEALTH * (1-random.random()*0.3))),
            random_health_total(MAX_MINIONS, math.floor(MAX_SIDE_HEALTH * (1-random.random()*0.3))),
            -random.randint(1, 10),
            'large')

    for i in range(15):
        x = random.randint(1, MAX_MINIONS)
        y = random.randint(1, MAX_MINIONS)
        xminions = random_health_total(x, math.ceil(MAX_HEALTH * x * random.random()))
        yminions = random_health_total(y, math.ceil(MAX_HEALTH * y * random.random()))
        damage = random.randint(sum(yminions), sum(xminions) + sum(yminions))
        add_case(xminions, yminions, damage, 'random')



if __name__ == '__main__':
    main()
