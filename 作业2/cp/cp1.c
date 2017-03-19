#include <stdio.h>      
#include <stdlib.h>    
#include <string.h>    
#include <fcntl.h>     
#include <errno.h>      
#include <unistd.h>     
#include <sys/types.h>
#include <sys/stat.h>  
#define rwmode 2
#define BUFFER_SIZE 1

int main()
{
   int from_fd,to_fd;
   int bytes_read,bytes_write;
   char buffer[BUFFER_SIZE];
   char *ptr;
 
   if((from_fd=open("file",rwmode))==-1)   
   {
     printf("Open Error\n");
     exit(1);
   }
 
   if((to_fd=open("file2",rwmode))==-1) 
   {
     printf("Open  Error\n");
     exit(1);
   }
  while(bytes_read=read(from_fd,buffer,BUFFER_SIZE))
   {
    
     if((bytes_read==-1)&&(errno!=EINTR)) 
         break;
     else if(bytes_read>0)
     {
       ptr=&buffer[0];
       while(bytes_write=write(to_fd,ptr,bytes_read))
       {
       
         if((bytes_write==-1)&&(errno!=EINTR))
             break;
        
         else if(bytes_write==bytes_read) 
             break;
       
         else if(bytes_write>0)
         {
           ptr+=bytes_write;
           bytes_read-=bytes_write;
         }
       }
     
       if(bytes_write==-1)
           break;
     }
   }
   close(from_fd);
   close(to_fd);	//
   return;
 }
