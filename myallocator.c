#include<stdio.h>
#include<stddef.h>

char mymemory[8000];

struct block{
 size_t size;
 int free;
 struct block *next; 
};

typedef struct block block;

 block *list=(void*)mymemory;


void initmemory()
{
  //TO DO
  //Initialize the list size, free and next
  size = 8000 - 4  // initial size of the memory block - size of metadata block
  free = 1; //entire block is free
  next = NULL; //one element in list

}

void split( block *slotToBeSplitted,size_t size)
{
  //TO DO
  //Split the slot to be splitted and create a new slot 
  int newBlockSize = slotToBeSplitted -> size - size - sizeof(struct metadatablock);
  block *newBlock;
  newBlock -> size = newBlockSize;
  newBlock -> next = slotToBeSplitted-> next;
  newBlock -> free = 1;

  slotToBeSplitted -> size = slotToBeSplitted -> size - newBlockSize + sizeof(struct metadatablock);
  slotToBeSplitted -> next = newBlock; 
  slotToBeSplitted -> free = 0;
}


void *NewMalloc(size_t allocSize)
{
 block *curr;
 void *result;
 curr=list;
 
 //TO DO
 //Find a chunk with enough free space
 while(curr -> next != NULL){
   if(curr -> size >= allocSize)
   {
     break;
   }
   curr = curr->next;
 }

 printf("curr size is: %d\n\n", curr->size);

 //TO DO
 //Check cases and allocate with/without splitting
 int extraspace = curr->size - allocSize;
 if(extraspace = 0)
 {
   //in this case, no need to split
   
 }

}

void coalesce(){
 struct block *curr;
 curr=list;
 //TO DO
 //Coalesce consequtive free blocks
}

void NewFree(void* ptr){
  //TO DO
  //Check if the pointer is in a valid range
  //If yes, free the block and call coalesce

}

int main(){
 
 if(!(list->size))
 {
  initmemory();
  printf("\n\n--Memory Initialization Completed--\n");
  printf("Initial size is: %d\n\n", list->size);
 }


 int *p=(int*)NewMalloc(800);
 printf("\n");
 char *q=(char*)NewMalloc(250*sizeof(char));
 printf("\n");
 int *r=(int*)NewMalloc(1000*sizeof(int));
 printf("\n");
 NewFree(p);
 printf("\n");
 char *w=(char*)NewMalloc(1000);
 printf("\n");
 NewFree(r);
 printf("\n");
 int *k=(int*)NewMalloc(1500*sizeof(int));
 printf("\n");

}
