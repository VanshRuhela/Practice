#include <iostream>
using namespace std;
int main(){
    int i =0;
    for(;;){
        if(i == 10)
        continue;

        printf("%d", ++i);

    }
    

    return 0;
}