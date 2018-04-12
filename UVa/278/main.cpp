
#include <stdio.h>
#define min(x,y)	(x<y)?x:y

int main(){

    int cases,i,m,n,ans;
    char piece;
    scanf("%d\n",&cases);
    //printf("%d\n",cases);
    for(i=0;i<cases;i++){

        scanf("%c %d %d\n",&piece,&m,&n);
        //printf("%d %d %d\n",piece,m,n);
        //printf("%c %d %d\n",piece,m,n);
        switch(piece){
            case 'r': ans = min(m,n); break;
            case 'k': ans = (m*n)>>1; break;
            case 'Q': ans = min(m,n); break;
            case 'K': ans = (((m+1)&~1)>>1) * (((n+1)&~1)>>1); break;
        }
        printf("%d\n",ans);

    }
    return 0;
}