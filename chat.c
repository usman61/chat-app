#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{

int pfd1[2],pfd2[2];
pipe(pfd1);
pipe(pfd2);
char buf[30];


int child=fork();

while(1){

if (child == 0)

{

    close(pfd1[1]);   // closing for reading p1
    close(pfd2[0]);   // closing writing for p2


    read(pfd1[0],buf,sizeof(buf));
    printf("P1 says : %s\n",buf);

    printf("P2: ");
    fgets(buf,sizeof(buf),stdin);

    write(pfd2[1],buf,sizeof(buf));


}


else
  {

    printf("P1: ");
    fgets(buf,sizeof(buf),stdin);

    close(pfd1[0]);   // closing for reading p1
    close(pfd2[1]);   // closing writing for p2
    write(pfd1[1],buf,sizeof(buf));


    read(pfd2[0],buf,sizeof(buf));
    printf("P2 says : %s\n",buf);


  }
}

}
