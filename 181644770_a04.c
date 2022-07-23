#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//void firstfit (char * memory,  processreg* register,int noofbytes);

int initcount=0;

    

   typedef struct processreg{
        
        char process[20];
        int base;
        int limit;
        int memoryset; //flag to check if memory has been initialized//
        
    }processreg;
    


void firstfit (char * memory,processreg *xegister,int noofbytes,char process_number[4])
{
    int count;
    int basereg;
    //look for free space in memory//
    if(initcount==0){
        
        memset(memory,'1',noofbytes);
        strcpy((xegister)->process,process_number);
        (xegister)->base=0;
        (xegister)->limit=noofbytes;
        (xegister)->memoryset=1;
        //printf("%d",(xegister)->base);
    }
    else{
            for(int i=0; i<10; i++){
            if(i!=0)    
                if((xegister+i)->memoryset==0){
                    // printf("%d",(xegister+(i-1))->limit);
                    memset(memory+(xegister+(i-1))->limit+1+(xegister+(i-1))->base,'1',noofbytes);
                    strcpy((xegister+i)->process,process_number);
                    (xegister+i)->memoryset=1;
                    (xegister+i)->base=((xegister+(i-1))->limit)+((xegister+(i-1))->base);
                    (xegister+i)->limit=noofbytes;
                    
                    break;
                }
            else{
                if((xegister+i)->memoryset==0){
                    
                    memset(memory+(xegister+(i-1))->limit+1+(xegister+(i-1))->base,'1',noofbytes);
                    strcpy((xegister+i)->process,process_number);
                    (xegister+i)->memoryset=1;
                    (xegister+i)->base=((xegister+(i-1))->limit)+((xegister+(i-1))->base);
                    (xegister+i)->limit=noofbytes;
                    
            }    
                
                
            }
                        

        }
    }    
        
    // for(int i=0; i<=600; i++){
    // printf("%c" ,*(memory+i));
    // }
}
    
  
    
    


void worstfit (char * memory,processreg *xegister,int noofbytes,char process_number[4])
{
    
    int flag=0;
    int fragarray[10]={-1 , -1, -1, -1, -1, -1, -1, -1, -1, -1};
    
    if(initcount==0){
        
        memset(memory,'1',noofbytes);
        strcpy((xegister)->process,process_number);
        (xegister)->base=0;
        (xegister)->limit=noofbytes;
        (xegister)->memoryset=1;
    }    
    else{

        for(int i=0; i < 10; i++){
            if((xegister+i)->memoryset==0 && (xegister+i)->limit!=0){
                if(xegister->limit>=noofbytes)
                fragarray[i]=xegister->limit-noofbytes;
                flag=1;
                
            }
            else if((xegister+i)->memoryset==0 && (xegister+i)->limit==0){
                
               fragarray[i]=(1024*1024)-((xegister+(i-1))->base+(xegister+(i-1))->limit)-noofbytes;
               break;
            }
            
       
        }
        int min=-1;
        int i=0;
        int minindex;
        if (flag==1){
        while(i < 10 ){
        if(i!=0){
            if(fragarray[i]!=-1 && fragarray[i]>min){
                minindex=i;
                min=fragarray[i];
            }
        }
        else{
            if(fragarray[i]!=-1){
            minindex=i;
            min=fragarray[i];
            }
        }
            i++;
        }
        memset(memory+(xegister+minindex)->base,'1',noofbytes);
        strcpy((xegister+minindex)->process,process_number);
               (xegister+minindex)->limit=noofbytes;
                (xegister+minindex)->memoryset=1;
        }
       else if(flag==0){ 
        for(int i =0; i<10; i++){
            
        if((xegister+i)->memoryset==0 && (xegister+i)->limit==0){
            printf(":yo");
            printf("%d",(xegister+(i-1))->limit);
            memset(memory+((xegister+(i-1))->limit+1)+((xegister+(i-1))->base),'1',noofbytes);
            strcpy((xegister+i)->process,process_number);
            (xegister+i)->memoryset=1;
            (xegister+i)->base=((xegister+(i-1))->limit)+((xegister+(i-1))->base);
            (xegister+i)->limit=noofbytes;
            break;
                    
            
        }
        }
       }
    

    
    
    
}


}
void bestfit (char * memory,processreg *xegister,int noofbytes,char process_number[4])
{  
    int flag=0;
    int fragarray[10]={-1 , -1, -1, -1, -1, -1, -1, -1, -1, -1};
    
    if(initcount==0){
        
        memset(memory,'1',noofbytes);
        strcpy((xegister)->process,process_number);
        (xegister)->base=0;
        (xegister)->limit=noofbytes;
        (xegister)->memoryset=1;
    }    
    else{

        for(int i=0; i < 10; i++){
            if((xegister+i)->memoryset==0 && (xegister+i)->limit!=0){
                if(xegister->limit>=noofbytes)
                fragarray[i]=xegister->limit-noofbytes;
                flag=1;
                
            }
            else if((xegister+i)->memoryset==0 && (xegister+i)->limit==0){
                
               fragarray[i]=(1024*1024)-((xegister+(i-1))->base+(xegister+(i-1))->limit)-noofbytes;
               break;
            }
            
       
        }
        int min=-1;
        int i=0;
        int minindex;
        if (flag==1){
        while(i < 10 ){
        if(i!=0){
            if(fragarray[i]!=-1 && fragarray[i]<min){
                minindex=i;
                min=fragarray[i];
            }
        }
        else{
            if(fragarray[i]!=-1){
            minindex=i;
            min=fragarray[i];
            }
        }
            i++;
        }
        memset(memory+(xegister+minindex)->base,'1',noofbytes);
        strcpy((xegister+minindex)->process,process_number);
               (xegister+minindex)->limit=noofbytes;
                (xegister+minindex)->memoryset=1;
        }
       else if(flag==0){ 
        for(int i =0; i<10; i++){
            
        if((xegister+i)->memoryset==0 && (xegister+i)->limit==0){
            // printf(":yo");
            // printf("%d",(xegister+(i-1))->limit);
            memset(memory+((xegister+(i-1))->limit+1)+((xegister+(i-1))->base),'1',noofbytes);
            strcpy((xegister+i)->process,process_number);
            (xegister+i)->memoryset=1;
            (xegister+i)->base=((xegister+(i-1))->limit)+((xegister+(i-1))->base);
            (xegister+i)->limit=noofbytes;
            break;
                    
            
        }
        }
       }
        // for(int i=0;i<10;i++){    
        // printf("\n%d\n",fragarray[i]);
        
        // }
     
        
        
        
       
        
        
        
    }
    //   for(int i=0; i<=600; i++){
    //         printf("%c" ,*(memory+i));
    //     }

}

int main ()
{
    

 processreg processregarray[10]={0};
    
  char str[50];
  char process_number[4];
  int numberofbytes;
  char algorithm;
  
  //int process_number;
  int x = 0;
  int sum=0;
  char *memory = (char*)malloc(1024*1024);
  while (x == 0)
    {

      printf (">allocator ");
      
      //if()
      //check what user wants to do RL OR RQ 
      scanf("%6s",str);
      if(strcmp(str,"EXIT")==0){
          break;
      }
      if(strcmp(str,"RQ")==0){
      scanf("%3s %d %c",process_number,&numberofbytes,&algorithm);
      }
      else if(strcmp(str,"RL")==0){
          scanf("%2s",process_number);
      }
      
      //scanf("%s",process_number);
      //printf("%6s", str);
      //printf("%d", numberofbytes);
      //printf("%c",process_number[0]);
      
      if (strcmp (str, "RQ") == 0)
	{
	    
	    
	    //printf ("something\n");
	    if(algorithm=='B'){
	        
	        
	        //call bestfit
	        bestfit (memory,processregarray,numberofbytes,process_number);
	        printf("succsessfully allocated %d to process %s",numberofbytes,process_number);
	        initcount++;
	        
	    }
	    if(algorithm=='F'){
	        
	        //call firstfit
	        //printf("i am here\n");
	        firstfit(memory,processregarray,numberofbytes,process_number);
	        printf("succsessfully allocated %d to process %s",numberofbytes,process_number);
	        initcount++;
	        
	    }
	    if(algorithm == 'W'){
	        
	        //call worstfit
	        worstfit(memory,processregarray,numberofbytes,process_number);
	        initcount++;
	        
	    }

	}
    else if (strcmp (str, "RL") == 0)
	{
	    //printf("i am here");
	    for(int i=0; i<10; i++){
	        if(strcmp(processregarray[i].process,process_number)==0){
	            
	            processregarray[i].memoryset=0;
	            memset(memory+processregarray[i].base,'0',processregarray[i].limit+1);
	            printf("releasing memory for process %s ",process_number);
	            printf("succsessfully relesed memory for %s",process_number);
	        }
	        
	        
	    }
	   // for(int i=0;i<=400;i++){
	   //     printf("%c" ,*(memory+i));
	   // }
	    

	}
	else if (strcmp (str, "Status") == 0){
	    //printf("inside Status");
	    for(int i=0; i<10; i++){
	        if(processregarray[i].memoryset == 1){
	            sum =sum +processregarray[i].limit;     
	            
	        }
	    }
	    printf("\npartitions[memory allocated = %d]\n",sum);
	    for(int i=0; i<10; i++){
	        if(processregarray[i].memoryset==1){
	    printf("Address: %d:%d process %s \n",processregarray[i].base,processregarray[i].base+processregarray[i].limit,processregarray[i].process);
	    //printf("Address: %d:%d process %s  \n",processregarray[i].base,processregarray[i].base+processregarray[i].limit,processregarray[i].process);
	    
	        }
	    }
	    printf("Holes {free memory = %d}\n",(1024*1024)-sum);
	    for(int i=0; i<initcount; i++){
	        if(processregarray[i].memoryset==0 && processregarray[i].limit==0){
	            printf("Address [%d:%d]=%d\n:",(processregarray[i-1].base+processregarray[i-1].limit),(1024*1024),(1024*1024)-(processregarray[i-1].base+processregarray[i-1].limit));
	        }
	        else if(processregarray[i].memoryset==0 && processregarray[i].limit!=0){
	            printf("Address [%d:%d]=%d\n",(processregarray[i].base),processregarray[i].limit,processregarray[i].limit-processregarray[i].base);
	        }
	            
	        }
	        
	    }
	    
	
        

      //printf("%s",str);

      


    }
    free(memory);
}