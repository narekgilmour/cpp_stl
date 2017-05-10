Copy the given file contents without using any fstream objects and/or methods, without using read() and write() POSIX functions and without any kind of FILE* related functions.
Reading must be organized by the "cin >>" operator, and writing - with the "cout <<" operator.
Hint: replace the stdin and stdout streams by the appropriate file descriptors.


#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

int main(int argc,char* argv[])
{

  //AT the first we look if we have enough argumets
  if (argc==1)
  {
    cout<<"You didn't give arguments"<<endl;
    return -1;
  }
  if (argc==2)
  {
    cout<<"There is not enough arguments you give one"<<endl;
  return -1;
}
  if(argc>3)

{
  cout<<"You gave more arguments we need"<<endl;
  return -1;
}

//creation of the first file and writing containment

int out = dup(1); //dublicating stdout file descriptor to least free descriptor
close(1);
int file =open(argv[1],O_CREAT|O_WRONLY,0777);
dup2(file,1);  //with dub2 we dublicating our file descriptor to 1
cout<<"some text"<<endl;
close(1);
dup2(out,1); //dublicationg stdout file descriptor again back to 1

//copying first file containment to seconf file

int in_1 = dup(0); //dublicating stdin and stdout file descriptors to least free descriptors
int out_1 = dup(1);
close(0); // deleting
close(1);

int first_file=open(argv[1],O_RDONLY, 0777);
int second_file=open(argv[2],O_CREAT|O_WRONLY, 0777);

dup2(first_file,0);
dup2(second_file,1);

//reading from first_file and writing to the second_file

char m;
while (std::cin.get(m))
 {
  std::cout<< m;
}
close(first_file);
close(second_file);
 dup2(in_1,0); //returning stdin and stdout file descriptors
 dup2(out_1,1);

return 0;
}