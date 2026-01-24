#include <stdio.h>
#include <math.h>
#include <assert.h>

int signeProduit(int a, int b) {
    if (((a<0) && (b<0)) || ((a>0) && (b>0))) {
        return 1;
    } else {
        if ((a==0) || (b==0)) {
            return 0;
        }
    }
    return -1;
}

int main() {
    assert(signeProduit(-1,2)==-1);
    assert(signeProduit(-1,0)==0);
    assert(signeProduit(1,1)==1);
    return 0;
}