/*meena loves sweets and wants the sweetness of some cookies to be greater than value K. To do this, 2 cookies with the least sweetness are repeatedly mixed this creates a special combined cookie with sweetness = (first least sweet cookie + second least sweet cookie) use link list to maintain all the cookies and add newly created cookies and the end of link list.*/
#include <stdio.h>
void mixCookies(int cookies[], int size, int k) {
    while(cookies[0] < k) {
        int first_least_sweet = cookies[0];
        int second_least_sweet = cookies[1];    
        int combined_sweetness = first_least_sweet + second_least_sweet;       
        // Move cookies one place to the left
        for(int i = 1; i < size-1; i++) {
            cookies[i] = cookies[i+1];
        }      
        // Add combined cookie at the end
        cookies[size-2] = combined_sweetness;
        size--;
    }
}
int main() {
    int cookies[] = {1, 3, 5, 9, 10, 15};
    int k = 10;
    int size = sizeof(cookies) / sizeof(cookies[0]);  
    mixCookies(cookies, size, k);    
    printf("Cookies with sweetness greater than %d: ", k);
    for(int i = 0; i < size; i++) {
        printf("%d ", cookies[i]);
    }  
    return 0;
}