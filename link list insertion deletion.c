#include<stdio.h>
#include<stdlib.h>
struct list
{
    char info[20];
    struct list *link;
};
struct list * start=NULL;
void traverse_list(struct list *);
struct list * insfirst(struct list *,char []);
struct list * avail_node();
struct list * delete_node(struct list*,char []);
void menu();
int main()
{
    menu();
    return 0;
}
void menu()
{
    while(1)
    {
        int ch;
        char item[20];
        system("cls");
        printf("\n");
        puts("<1> Insert node:");
        puts("<2> Delete node:");
        puts("<3> Display list:");
        puts("<4> Exit:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nItem: ");
            scanf("%s",&item);
            start=insfirst(start,item);
            break;
            case 2:printf("\nItem: ");
           scanf("%s",&item);
            start=delete_node(start,item);
            break;
            case 3:
                traverse_list(start);
            break;
            case 4: exit(0);
        }
    }
}
struct list* insfirst(struct list* start,char item[])
{
    struct list *new=avail_node();
   // new->info=item;
   strcpy(new->info,item);
    new->link=start;
    start=new;
    return start;
}
struct list * avail_node()
{
    struct list *avail=(struct list*)malloc(sizeof(struct list));
    if(avail==NULL)
    {
        printf("\noverflow");
        return 0;
    }
    else
    {
        return avail;
    }
}
void traverse_list(struct list * start)
{
    struct list * ptr;
    ptr=start;
    printf("\n\nLIST: ");
    if(ptr==NULL)
    {
        printf("list is empty");
    }
    printf("\n\nINFO\tLINK");
    while(ptr!=NULL)
    {
        printf("\n%-s\t%-u",ptr->info,ptr->link);
        ptr=ptr->link;
    }
    printf("\n");
    getch();
}
struct list * delete_node(struct list * start,char item[])
{
  struct list * loc=0, *locp=0;
  struct list *save,*ptr;
  if(start==NULL)
  {
      printf("\nList is Empty\n");
      return start;
  }
 // if(start->info==item)
 if(strcmp(start->info,item)==0)
  {
      loc=start;
      locp=NULL;
      start=start->link;
      free(loc);
      return start;
  }
  save=start;
  ptr=start->link;
  while(ptr!=NULL)
  {
      if(strcmp(ptr->info,item)==0)
      {
          loc=ptr;
          locp=save;
          locp=loc->link;
          free(loc);
          return start;
      }
      save=ptr;
      ptr=ptr->link;
  }
  return start;
}

