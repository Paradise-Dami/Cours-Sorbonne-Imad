#include <stdio.h>
#include <assert.h>

int alternative(int n1, int n2, int n3) {
    int res ;
    if (n1 > 8) {
    res = 3;
    } else {
        if (n3 == 20) {
        res = 2;
        } else {
            if ((n2 >= 10) && (n3 >= 10)) {
            res = 1;
            } else {
                res = 0;
            }
        }
    }
    return res;
    }
    int main(){
        assert(alternative(9,12,13) == 3); /*cas où n1>8*/
        assert(alternative(8,12,20) == 2); /*cas où n3=20 et n1<=8*/
        assert(alternative(7,19,18) == 1); /*cas où n1<=8? et n3!=20 et n2>=10 et n3>=10*/
        assert(alternative(7,8,9) == 0); /*cas où n1<=8? et n3!=20 et n2<10 et n3<10*/
    return 0;
    }
    