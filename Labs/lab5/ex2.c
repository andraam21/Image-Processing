#include<stdio.h>

int main(){
int a[5];
int i, k, x;
for(i=0; i<5; i++){
    scanf("%d", &a[i]);
}
scanf("%d", &k);
scanf("%d", &x);
for(i=3; i>k; i--){
    a[i+1] = a[i];

}
for(i=0; i<5; i++){
if(i==k){
a[i] = x;}
}
for(i=0; i<5; i++){
printf("%d", a[i]);
}
return 0;
}





