/*meena loves sweets and wants the sweetness of some cookies to be greater than value K. To do this, 2 cookies with the least sweetness are repeatedly mixed this creates a special combined cookie with sweetness = (first least sweet cookie + second least sweet cookie) use link list to maintain all the cookies and add newly created cookies and the end of link list.*/
#include <stdio.h>
void mCookies(int cookies[], int size, int k) {
    while(cookies[0] < k) 
{
        int leastsweet = cookies[0];
        int secondleastsweet =cookies[1];    
        int combinedsweetness = leastsweet + secondleastsweet;       
      
    for(int i = 1; i < s-1; i++) {
            cookies[i] = cookies[i+1];
        }      
     
       cookies[s-2] = combinedsweetness;
        s--;
    }
}
int main() {
    int cookies[] = {1, 3, 5, 9, 10, 15};
    int k = 10;
    int s = sizeof(cookies) / sizeof(cookies[0]);  
    mCookies(cookies, s, k);    
    printf("Cookies with sweetness greater than %d: ", k);
    for(int i = 0; i < s; i++) {
        printf("%d ", cookies[i]);
    }  
    return 0;
}