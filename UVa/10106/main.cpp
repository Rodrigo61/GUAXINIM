bool debug = false;

//<editor-fold desc="GUAXINIM TEMPLATE">
/********   All Required Header Files ********/
#include "bits/stdc++.h"
using namespace std;

#define all(container) container.begin(), container.end()
#define mp(i,j) make_pair(i,j)
#define space " "
#define pb push_back

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vii;


/// Debug Start
template<class T1> void deb(T1 e1)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << endl;
    }
}
template<class T1,class T2> void deb(T1 e1, T2 e2)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << space << e2 << endl;
    }
}
template<class T1,class T2,class T3> void deb(T1 e1, T2 e2, T3 e3)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << space << e2 << space << e3 << endl;
    }
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1, T2 e2, T3 e3, T4 e4)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << space << e2 << space << e3 << space << e4 << endl;
    }
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << space << e2 << space << e3 << space << e4 << space << e5 << endl;
    }
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1, T2 e2, T3 e3, T4 e4 ,T5 e5, T6 e6)
{
    if(debug) {
        cout << "[DEBUG]";
        cout << e1 << space << e2 << space << e3 << space << e4 << space << e5 << space << e6 << endl;
    }
}


template<typename T>
void print_vector_debug(const T& t) {

    if(debug) {
        cout << "[DEBUG] VECTOR:";
        for (auto i = t.cbegin(); i != t.cend(); ++i) {
            if ((i + 1) != t.cend()) {
                cout << *i << " ";
            } else {
                cout << *i << endl;
            }
        }
    }
}

template<typename T>
void print_array_debug(const T arr, int size){

    if(debug) {
        cout << "[DEBUG] VECTOR:";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << space;
        }
        cout << endl;
    }
}

template<typename T>
void print_2Darray_debug(const T arr, int rows, int cols){

    if(debug) {
        cout << "[DEBUG] Matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << arr[i][j] << space;
            }
            cout << endl;
        }
        cout << endl;
    }
}

template<typename T>
void print_matrix_debug(const T& t) {
    if(debug) {
        cout << "[DEBUG] MATRIX:" << endl;
        for (auto i = t.cbegin(); i != t.cend(); ++i) {
            for(auto j = i->cbegin(); j != i->cend(); ++j){
                cout << *j << " ";
            }
            cout << endl;
        }
    }
}
//</editor-fold>

#define TO_INT(c) (int)((char)c - '0')
#define TO_CHAR(i) (char)((int)i + '0')

string mult_by_digit(string &num, char digit) {

    string res;
    int carry = 0;
    int sz = num.size();

    for (int i = sz - 1; i >= 0; --i) {

        int num_i = TO_INT(num[i]);
        int digit_num = TO_INT(digit);

        int digit_mult = num_i * digit_num + carry;
        carry = 0;

        if (digit_mult > 9) {
            carry = digit_mult / 10;
            digit_mult %= 10;
        }

        res.push_back(TO_CHAR(digit_mult));
    }

    if (carry != 0) {
        res.push_back(TO_CHAR(carry));
    }



    return res;

}

string add(string &num1, string &num2) {

    string res;
    int carry = 0;

    auto it1 = num1.begin(), it2 = num2.begin();

    while (it1 != num1.end() && it2 != num2.end()) {

        int digit_1 = TO_INT(*it1);
        int digit_2 = TO_INT(*it2);
        int digit_sum = digit_1 + digit_2 + carry;
        carry = 0;

        if (digit_sum > 9) {
            carry = 1;
            digit_sum -= 10;
        }

        deb("TO_CHAR(digit_sum) = ", TO_CHAR(digit_sum));
        res.pb(TO_CHAR(digit_sum));

        ++it1;
        ++it2;
    }


    while (it1 != num1.end()) {

        int digit_1 = TO_INT(*it1);
        int digit_sum = digit_1 + carry;
        carry = 0;

        if (digit_sum > 9) {
            carry = 1;
            digit_sum -= 10;
        }

        res.pb(TO_CHAR(digit_sum));

        ++it1;
    }

    while (it2 != num2.end()) {

        int digit_2 = TO_INT(*it2);
        int digit_sum = digit_2 + carry;
        carry = 0;

        if (digit_sum > 9) {
            carry = 1;
            digit_sum -= 10;
        }

        deb("digit_sum2 = ", digit_sum);
        res.pb(TO_CHAR(digit_sum));

        ++it2;
    }

    if (carry) {
        res.pb(TO_CHAR(carry));
    }

    return res;
}

string sum_all (vector<string> &sums) {

    string res = "0";

    for (auto &sum : sums) {
        res = add(res, sum);
    }

    return res;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string num1, num2;

    while (cin >> num1 >> num2) {

        if (num1 == "0" || num2 == "0") {
            printf("0\n");
            continue;
        }


        vector<string> sums;

        for (int i = 0; i < num1.size(); ++i) {
            string new_sum = mult_by_digit(num2, num1[num1.size() - 1 - i]);


            for (int j = 0; j < i; ++j) {
                new_sum = "0" + new_sum;
            }

            sums.push_back(new_sum);
        }


        string result = sum_all(sums);

        reverse(all(result));

        printf("%s\n", result.c_str());
    }

    return 0;
}
