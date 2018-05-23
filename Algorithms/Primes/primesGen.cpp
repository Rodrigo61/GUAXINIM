vi primes;

bool is_prime(int num) {

    if (num % 2 == 0) { return false; }

    int sqr = sqrt(num);
    for (int i = 3; i <= sqr; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

void calc_primes() {

    primes.push_back(2);
    for (int i = 3; i < 1000; ++i) {
        if (is_prime(i)) {
            primes.push_back(i);
        }
    }
}
