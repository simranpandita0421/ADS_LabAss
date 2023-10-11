/*meena loves sweets and wants the sweetness of some cookies to be greater than value K. To do this, 2 cookies with the least sweetness are repeatedly mixed this creates a special combined cookie with sweetness = (first least sweet cookie + second least sweet cookie) use link list to maintain all the cookies and add newly created cookies and the end of link list.*/
#include <stdio.h>
void mC(int c[], int s, int k)
 {
    while(c[0] < k) 
{
        int leastsweet = c[0];
        int secondleastsweet =c[1];    
        int combinedsweetness = leastsweet + secondleastsweet;       
      
    for(int i = 1; i < s-1; i++) {
            c[i] = c[i+1];
        }      
     
       c[s-2] = combinedsweetness;
        s--;
    }
}
int main() {
    int c[] = {1, 3, 5, 9, 10, 15};
    int k = 10;
    int s = sizeof(c) / sizeof(c[0]);  
    mC(c, s, k);    
    printf("Cookies with sweetness greater than %d: ", k);
    for(int i = 0; i < s; i++) 
{
        printf("%d ", c[i]);
    }  
    return 0;
}