#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"feat.h"

int NUM;

Indi_list* indi_list; Busi_list* busi_list; 
Org_list* org_list; Group_list* group_list;
// Intialising
void begin()
{   NUM=1;
    indi_list=NULL;
    busi_list=NULL;
    org_list=NULL;
    group_list=NULL;
}
// Showing Nodes
void show_basic(Node* key)
{
    if(key==NULL)
    {
        printf("Given Node Doesnt Exist\n");
    }
    printf("ID : %d\n",key->id);
    printf("Name : %s\n",key->name);
    printf("Creation Date : %s\n",key->creation);
}
void show_posts(Node* key)
{
    if(key==NULL)
    {
        printf("Given Node Doesnt Exist\n"); return;
    }
    if(key->content==NULL) return;
    post_link* ptr=key->content;
    while(ptr!=NULL)
    {
        printf("--> %s\n",ptr->post);
        ptr=ptr->next;
    }
}

void show_indi(Indi* ind)
{
    if(ind==NULL)
    {
        printf("Given Node Doesnt Exist\n"); return;
    }
    show_basic(ind->basic_info);  printf("\n");
    if(ind->birth[0]!='\0') printf("Birthday : %s\n",ind->birth);
}
void show_busi(Busi* bus)
{
    if(bus==NULL)
    {
        printf("Given Node Doesnt Exist\n"); return;
    }
    show_basic(bus->basic_info);  printf("\n");
    printf("Location : (%d,%d)\n",bus->location.x,bus->location.y);
}
void show_org(Org* orga)
{
    if(orga==NULL)
    {
        printf("Given Node Doesnt Exist\n"); return;
    }
    show_basic(orga->basic_info); printf("\n");
    printf("Location : (%d,%d)\n",orga->location.x,orga->location.y);
}
void show_group(Group* grp)
{
    if(grp==NULL)
    {
        printf("Given Node Doesnt Exist\n"); return;
    }
    show_basic(grp->basic_info); printf("\n");
}

// Searching Nodes (Used By a Lot of other functions)
Indi* search_id_indi(int idd)
{
    Indi_list* ptr=indi_list;
    while(ptr!=NULL)
    {
        if(ptr->present->basic_info->id==idd) {return(ptr->present);}
        ptr=ptr->next;
    } ptr=NULL; free(ptr);
    return(NULL);
}
Busi* search_id_busi(int idd)
{
    Busi_list* ptr=busi_list;
    while(ptr!=NULL)
    {
        if(ptr->present->basic_info->id==idd) {return(ptr->present);}
        ptr=ptr->next;
    } ptr=NULL; free(ptr);
    return(NULL);
}
Org* search_id_org(int idd)
{
    Org_list* ptr=org_list;
    while(ptr!=NULL)
    {
        if(ptr->present->basic_info->id==idd) {return(ptr->present);}
        ptr=ptr->next;
    } ptr=NULL; free(ptr);
    return(NULL);
}
Group* search_id_group(int idd)
{
    Group_list* ptr=group_list;
    while(ptr!=NULL)
    {
        if(ptr->present->basic_info->id==idd) {return(ptr->present);}
        ptr=ptr->next;
    } ptr=NULL; free(ptr);
    return(NULL);
}

int search_by_name()
{
    char namee[100]; printf("Enter Name : "); scanf(" %[^\n]s",namee);
    Indi_list* pt1=indi_list; int i=0,j=0;
    while(pt1!=NULL)
    {
        printf("%d> ",i+1); i++; j=0;
        if(strstr(pt1->present->basic_info->name,namee))
        {show_indi(pt1->present); printf("\n");}
        pt1=pt1->next;
    } free(pt1);
    Busi_list* pt2=busi_list;
    while(pt2!=NULL)
    {
        printf("%d> ",i+1); i++; j=0;
        if(strstr(pt2->present->basic_info->name,namee))
        {show_busi(pt2->present); printf("\n");}
        pt2=pt2->next;
    } free(pt2);
    Group_list* pt3=group_list;
    while(pt3!=NULL)
    {
        printf("%d> ",i+1); i++; j=0;
        if(strstr(pt3->present->basic_info->name,namee))
        {show_group(pt3->present); printf("\n");}
        pt3=pt3->next;
    } free(pt3);
    Org_list* pt4=org_list;
    while(pt4!=NULL)
    {
        printf("%d> ",i+1); i++; j=0;
        if(strstr(pt4->present->basic_info->name,namee))
        {show_org(pt4->present); printf("\n");}
        pt4=pt4->next;
    } free(pt4); 
    if(i==0) return(0);
    printf("Following searches match. Choose id to specify\n");
    int idd; scanf("%d",&idd); return(idd);
}
int search_by_id()
{
    int idd; printf("Enter ID : "); scanf("%d",&idd);
    return(idd);
}
int search_by_birthday()
{
    char birthh[100]; printf("Enter BirthDay : "); scanf(" %[^\n]s",birthh);
    Indi_list* pt1=indi_list; int i=0,j=0;
    while(pt1!=NULL)
    {
        printf("%d> ",i+1); i++;
        if(strstr(pt1->present->birth,birthh))
        {
            printf("%d> ",++i); 
            show_indi(pt1->present); printf("\n");
        }
        pt1=pt1->next;
    } free(pt1); 
    if(i==0) return(0);
    printf("Following searches match. Choose id to specify\n");
    int idd; scanf("%d",&idd); return(idd);
}
int search_by_type()
{
    int Type; printf("Enter Type (1>Individual 2>Business 3>Group 4>Organisation) : "); scanf("%d",&Type);
    while(Type>4 || Type<1)
    {
        printf("Please Enter a Valid Type : ");
        scanf("%d",&Type);
    } int i;
    if(Type==1)
    {
        Indi_list* ptr=indi_list; i=0;
        while(ptr!=NULL)
        {
            printf("%d> ",i+1); i++;
            show_indi(ptr->present); printf("\n");
            ptr=ptr->next;
        }
    }
    else if(Type==2)
    {
        Busi_list* ptr=busi_list; i=0;
        while(ptr!=NULL)
        {
            printf("%d> ",i+1); i++;
            show_busi(ptr->present); printf("\n");
            ptr=ptr->next;
        }
    }
    else if(Type==3)
    {
        Group_list* ptr=group_list; i=0;
        while(ptr!=NULL)
        {
            printf("%d> ",i+1); i++;
            show_group(ptr->present); printf("\n");
            ptr=ptr->next;
        }
    }
    else 
    {
        Org_list* ptr=org_list; i=0;
        while(ptr!=NULL)
        {
            printf("%d> ",i+1); i++;
            show_org(ptr->present); printf("\n");
            ptr=ptr->next;
        }
    } int idd;
    if(i==0) return(0);
    printf("Following searches match. Choose id to specify\n");
    scanf("%d",&idd); return(idd);
}

int search()
{
    printf("Search by? 1>Id 2>Name 3>Type 4>Birthday"); int opt;
    while(opt<1 || opt>4)
    {
        printf("Please choose between 1-4: ");
        scanf("%d",&opt);
    }
    int idd;
    if(opt==1) idd=search_by_id(); 
    else if(opt==2) idd=search_by_name(); 
    else if(opt==3) idd=search_by_type(); 
    else idd=search_by_birthday();
    return(idd);
}

// Search and Show
// Doesnt return anything,only for showing
void actual_search_by_name()
{
    char namee[100]; printf("Enter Name : "); scanf(" %[^\n]s",namee);
    Indi_list* pt1=indi_list; int i=0,j=0;
    while(pt1!=NULL)
    {
        if(strstr(pt1->present->basic_info->name,namee))
        {show_indi(pt1->present); printf("\n");}
        pt1=pt1->next;
    }
    Busi_list* pt2=busi_list;
    while(pt2!=NULL)
    {
        if(strstr(pt2->present->basic_info->name,namee))
        {show_busi(pt2->present); printf("\n");}
        pt2=pt2->next;
    }
    Group_list* pt3=group_list;
    while(pt3!=NULL)
    {
        if(strstr(pt3->present->basic_info->name,namee))
        {show_group(pt3->present); printf("\n");}
        pt3=pt3->next;
    }
    Org_list* pt4=org_list;
    while(pt4!=NULL)
    {
        if(strstr(pt4->present->basic_info->name,namee))
        {show_org(pt4->present); printf("\n");}
        pt4=pt4->next;
    }
    if(i==0) {printf("No Id found with the given name\n"); pt4=NULL; free(pt4); return;}
    printf("Above searches match.\n");
}
void actual_search_by_id()
{
    int idd; printf("Enter ID : "); scanf("%d",&idd);
    Indi_list* pt1=indi_list; int i=0;
    while(pt1!=NULL)
    {
        if(pt1->present->basic_info->id==idd)
        {
            printf("%d> ",++i);
            show_indi(pt1->present); printf("\n"); pt1=NULL; free(pt1); return;}
        pt1=pt1->next;
    } pt1=NULL; free(pt1);
    Busi_list* pt2=busi_list;
    while(pt2!=NULL)
    {
        if(pt2->present->basic_info->id==idd)
        {
            printf("%d> ",++i);
            show_busi(pt2->present); printf("\n"); pt2=NULL; free(pt2); return;}
        pt2=pt2->next;
    } pt2=NULL; free(pt2);
    Group_list* pt3=group_list;
    while(pt3!=NULL)
    {
        if(pt3->present->basic_info->id==idd)
        {
            printf("%d> ",++i);
            show_group(pt3->present); printf("\n"); pt3=NULL; free(pt3); return;}
        pt3=pt3->next;
    } pt3=NULL; free(pt3);
    Org_list* pt4=org_list;
    while(pt4!=NULL)
    {
        if(pt4->present->basic_info->id==idd)
        {
            printf("%d> ",++i);
            show_org(pt4->present); printf("\n"); pt4=NULL; free(pt4); return;}
        pt4=pt4->next;
    } pt4=NULL; free(pt4); 
    if(i==0) {printf("No Such ID Found\n"); return;}
}
void actual_search_by_birthday()
{
    char birthh[100]; printf("Enter BirthDay : "); scanf(" %[^\n]s",birthh);
    Indi_list* pt1=indi_list; int i=0,j=0;
    while(pt1!=NULL)
    {
        printf("%d> ",i+1); i++; j=0;
        if(strstr(pt1->present->birth,birthh))
        {
            printf("%d> ",++i); 
            show_indi(pt1->present); printf("\n");
        }
        pt1=pt1->next;
    } 
    if(i==0) {printf("No node with given Birthday Found :(\n");return;}
    printf("Above searches match.\n");
}
void actual_search_by_type()
{
    int Type; printf("Enter Type (1>Individual 2>Business 3>Group 4>Organisation) : "); scanf("%d",&Type);
    while(Type>4 || Type<1)
    {
        printf("Please Enter a Valid Type : ");
        scanf("%d",&Type);
    } int i;
    if(Type==1)
    {
        Indi_list* ptr=indi_list; i=0;
        while(ptr!=NULL)
        {
            printf("%d> ",i+1); i++;
            show_indi(ptr->present); printf("\n");
            ptr=ptr->next;
        }
    }
    else if(Type==2)
    {
        Busi_list* ptr=busi_list; i=0;
        while(ptr!=NULL)
        {
            printf("%d> ",i+1); i++;
            show_busi(ptr->present); printf("\n");
            ptr=ptr->next;
        }
    }
    else if(Type==3)
    {
        Group_list* ptr=group_list; i=0;
        while(ptr!=NULL)
        {
            printf("%d> ",i+1); i++;
            show_group(ptr->present); printf("\n");
            ptr=ptr->next;
        }
    }
    else 
    {
        Org_list* ptr=org_list; i=0;
        while(ptr!=NULL)
        {
            printf("%d> ",i+1); i++;
            show_org(ptr->present); printf("\n");
            ptr=ptr->next;
        }
    }
    if(i==0) {printf("No node present in this type. :(\n"); return;}
    printf("Above searches match.\n");
}

void Actual_search()
{
    printf("Search by? 1>Id 2>Name 3>Type 4>Birthday"); int opt;
    while(opt<1 || opt>4)
    {
        printf("Please choose between 1-4: ");
        scanf("%d",&opt);
    }
    int idd;
    if(opt==1) actual_search_by_id(); 
    else if(opt==2) actual_search_by_name(); 
    else if(opt==3) actual_search_by_type(); 
    else actual_search_by_birthday();
}

// Creating Nodes 
Node* create_Node(char namee[],char creaton[])
{
    Node* key; key=(Node*)malloc(sizeof(Node));
    key->id=NUM++;
    strcpy(key->name,namee);
    strcpy(key->creation,creaton);
    key->content=NULL;
    return(key);
}

Indi* create_Indi()
{
    Indi* key=(Indi*)malloc(sizeof(Indi));  int idd; char namee[100],creaton[100];
    key=(Indi*)malloc(sizeof(Indi));
    key->busi_connect=NULL; key->group_connect=NULL; key->org_connect=NULL;
    printf("ID: %d\n",NUM);
    printf("Name: "); scanf(" %[^\n]s",namee);
    printf("Creation Date : "); scanf("%s",creaton);
    key->basic_info=create_Node(namee,creaton); int opt;
    printf("Do You want to Register Birthday?(Yes\\No) : "); scanf("%s",namee);

    if(namee[0]=='Y' || namee[0]=='y')
    {
        printf("BirthDay(optional) : "); scanf("%s",key->birth);
    }
    else strcpy(key->birth,"\0");
    printf("Linked to?\n1> None 2> Bussiness 3> Organisation 4>Group\n (Any other key corresponds to 'None') : ");
    scanf("%d",&opt); //Till here okay
    if(opt==2)
    {
        printf("Business id? "); scanf("%d",&idd);
        Busi* pt=search_id_busi(idd);
        if(pt==NULL) printf("Key Not Found\n");
        if(pt!=NULL)
        {
            if(key->busi_connect==NULL) {
                key->busi_connect=(Busi_conn_link*)malloc(sizeof(Busi_conn_link));
                key->busi_connect->conn = pt; 
                key->busi_connect->next=NULL;
            }
            else
            {
                Busi_conn_link* temp=(Busi_conn_link*)malloc(sizeof(Busi_conn_link));
                temp->conn=pt;
                temp->next=key->busi_connect;
                key->busi_connect=temp;
            }
            if(pt->indi_connect==NULL) {
                pt->indi_connect=(Indi_conn_link*)malloc(sizeof(Indi_conn_link));
                pt->indi_connect->conn=key; 
                pt->indi_connect->next=NULL;
            }
            else{
                Indi_conn_link* temp=(Indi_conn_link*)malloc(sizeof(Indi_conn_link));
                temp->conn=key;
                temp->next=pt->indi_connect;
                pt->indi_connect=temp;
            }
        }
    }
    else if(opt==3)
    {
        printf("Organisation Id? "); scanf("%d",&idd);
        Org* pt=search_id_org(idd);
        if(pt==NULL) printf("Key Not Found\n");
        if(pt!=NULL)
        {
            if(key->org_connect==NULL) {
                key->org_connect=(Org_conn_link*)malloc(sizeof(Org_conn_link));
                key->org_connect->conn = pt; 
                key->org_connect->next=NULL;
            }
            else
            {
                Org_conn_link* temp=(Org_conn_link*)malloc(sizeof(Org_conn_link));
                temp->conn=pt;
                temp->next=key->org_connect;
                key->org_connect=temp;
            }
            if(pt->indi_connect==NULL) {
                pt->indi_connect=(Indi_conn_link*)malloc(sizeof(Indi_conn_link));
                pt->indi_connect->conn=key; 
                pt->indi_connect->next=NULL;
            }
            else{
                Indi_conn_link* temp=(Indi_conn_link*)malloc(sizeof(Indi_conn_link));
                temp->conn=key;
                temp->next=pt->indi_connect;
                pt->indi_connect=temp;
            }
        }
    }
    else if(opt==4)
    {
        printf("Group Id? "); scanf("%d",&idd);
        Group* pt=search_id_group(idd);
        if(pt==NULL) printf("Key Not Found\n");
        if(pt!=NULL)
        {
            if(key->group_connect==NULL) {
                key->group_connect=(Group_conn_link*)malloc(sizeof(Group_conn_link));
                key->group_connect->conn = pt; 
                key->group_connect->next=NULL;}
            else
            {
                Group_conn_link* temp=(Group_conn_link*)malloc(sizeof(Group_conn_link));
                temp->conn=pt;
                temp->next=key->group_connect;
                key->group_connect=temp;
            }
            if(pt->indi_connect==NULL) {
                pt->indi_connect=(Indi_conn_link*)malloc(sizeof(Indi_conn_link));
                pt->indi_connect->conn=key; 
                pt->indi_connect->next=NULL;
            }
            else{
                Indi_conn_link* temp=(Indi_conn_link*)malloc(sizeof(Indi_conn_link));
                temp->conn=key;
                temp->next=pt->indi_connect;
                pt->indi_connect=temp;
            }
        }
    }
    if(indi_list==NULL)
    {
        indi_list=(Indi_list*)malloc(sizeof(Indi_list));
        indi_list->present=key;
        indi_list->next=NULL;
    }
    else{
        Indi_list* temp=(Indi_list*)malloc(sizeof(Indi_list));
        temp->present=key;
        temp->next=indi_list;
        indi_list=temp;
    }
    printf("Node Created\n");
    return(key);
}
Busi* create_Busi()
{
    Busi* key=(Busi*)malloc(sizeof(Busi));  int idd; char namee[100],creaton[100];
    key->indi_connect=NULL; key->group_connect=NULL;
    printf("ID: %d\n",NUM);
    printf("Name: "); scanf(" %[^\n]s",namee);
    printf("Creation Date: "); scanf("%s",creaton);
    key->basic_info=create_Node(namee,creaton); 
    printf("Location : "); scanf("%d",&key->location.x); scanf("%d",&key->location.y);
    int opt;
    printf("Linked to?\n1> None 2>Group\n Any other key corresponds to none\n");
    scanf("%d",&opt);
    if(opt==2)
    {
        printf("Group Id? "); scanf("%d",&idd);
        Group* pt=search_id_group(idd);
        if(pt==NULL) printf("Key Not Found\n");
        if(pt!=NULL)
        {
            if(key->group_connect==NULL) {
                key->group_connect=(Group_conn_link*)malloc(sizeof(Group_conn_link));
                key->group_connect->conn = pt; 
                key->group_connect->next=NULL;
            }
            else
            {
                Group_conn_link* temp=(Group_conn_link*)malloc(sizeof(Group_conn_link));
                temp->conn=pt;
                temp->next=key->group_connect;
                key->group_connect=temp;
            }
            if(pt->busi_connect==NULL) {
                pt->busi_connect=(Busi_conn_link*)malloc(sizeof(Busi_conn_link));
                pt->busi_connect->conn=key; 
                pt->busi_connect->next=NULL;
            }
            else{
                Busi_conn_link* temp=(Busi_conn_link*)malloc(sizeof(Busi_conn_link));
                temp->conn=key;
                temp->next=pt->busi_connect;
                pt->busi_connect=temp;
            }
        }
    } int no;

    printf("Number of owners : "); scanf("%d",&no); if(no>0) printf("Enter Id of the Owners : ");
    for(int i=0;i<no;i++)
    {
        printf("%d> ",i+1); scanf("%d",&idd);
        Indi* pt=search_id_indi(idd);
        if(pt==NULL) printf("Key Not Found\n");
        if(pt!=NULL)
        {
            if(key->indi_connect==NULL) {
                key->indi_connect=(Indi_conn_link*)malloc(sizeof(Indi_conn_link));
                key->indi_connect->conn = pt; 
                key->indi_connect->next=NULL;
            }
            else
            {
                Indi_conn_link* temp=(Indi_conn_link*)malloc(sizeof(Indi_conn_link));
                temp->conn=pt;
                temp->next=key->indi_connect;
                key->indi_connect=temp;
            }
            if(pt->busi_connect==NULL) {
                pt->busi_connect=(Busi_conn_link*)malloc(sizeof(Busi_conn_link));
                pt->busi_connect->conn=key; 
                pt->busi_connect->next=NULL;
            }
            else{
                Busi_conn_link* temp=(Busi_conn_link*)malloc(sizeof(Busi_conn_link));
                temp->conn=key;
                temp->next=pt->busi_connect;
                pt->busi_connect=temp;
            }
        }
    }
    printf("Number of Customers : "); scanf("%d",&no); if(no>0) printf("Enter Id of the Customers : ");
    for(int i=0;i<no;i++)
    {
        printf("%d> ",i+1); scanf("%d",&idd);
        Indi* pt=search_id_indi(idd);
        if(pt==NULL) printf("Key Not Found\n");
        if(pt!=NULL)
        {
            if(key->indi_connect==NULL) {
                key->indi_connect=(Indi_conn_link*)malloc(sizeof(Indi_conn_link));
                key->indi_connect->conn = pt; 
                key->indi_connect->next=NULL;
            }
            else
            {
                Indi_conn_link* temp=(Indi_conn_link*)malloc(sizeof(Indi_conn_link));
                temp->conn=pt;
                temp->next=key->indi_connect;
                key->indi_connect=temp;
            }
            if(pt->busi_connect==NULL) {
                pt->busi_connect=(Busi_conn_link*)malloc(sizeof(Busi_conn_link));
                pt->busi_connect->conn=key; 
                pt->busi_connect->next=NULL;
            }
            else{
                Busi_conn_link* temp=(Busi_conn_link*)malloc(sizeof(Busi_conn_link));
                temp->conn=key;
                temp->next=pt->busi_connect;
                pt->busi_connect=temp;
            }
        }
    }
    if(busi_list==NULL)
    {
        busi_list=(Busi_list*)malloc(sizeof(Busi_list));
        busi_list->present=key;
        busi_list->next=NULL;
    }
    else{
        Busi_list* temp=(Busi_list*)malloc(sizeof(Busi_list));
        temp->present=key;
        temp->next=busi_list;
        busi_list=temp;
    }
    printf("Node Created\n");
    return(key);
}
Org*  create_Org()
{
    Org* key=(Org*)malloc(sizeof(Org));  int idd; char namee[100],creaton[100];
    key->indi_connect=NULL;
    printf("ID: %d\n",NUM);
    printf("Name: "); scanf(" %[^\n]s",namee);
    printf("Creation Date: "); scanf("%s",creaton);
    key->basic_info=create_Node(namee,creaton); 
    printf("Location : "); scanf("%d",&key->location.x); scanf("%d",&key->location.y);
    int opt;
    int no;
    printf("Number of Individuals connected : "); scanf("%d",&no); if(no>0) printf("Enter Id of the Individuals : \n");
    for(int i=0;i<no;i++)
    {
        printf("%d> ",i+1); scanf("%d",&idd);
        Indi* pt=search_id_indi(idd);
        if(pt==NULL) printf("Key Not Found\n");
        if(pt!=NULL)
        {
            if(key->indi_connect==NULL) {
                key->indi_connect=(Indi_conn_link*)malloc(sizeof(Indi_conn_link));
                key->indi_connect->conn = pt; 
                key->indi_connect->next=NULL;
            }
            else
            {
                Indi_conn_link* temp=(Indi_conn_link*)malloc(sizeof(Indi_conn_link));
                temp->conn=pt;
                temp->next=key->indi_connect;
                key->indi_connect=temp;
            }
            if(pt->org_connect==NULL) {
                pt->org_connect=(Org_conn_link*)malloc(sizeof(Org_conn_link));
                pt->org_connect->conn=key; 
                pt->org_connect->next=NULL;
            }
            else{
                Org_conn_link* temp=(Org_conn_link*)malloc(sizeof(Org_conn_link));
                temp->conn=key;
                temp->next=pt->org_connect;
                pt->org_connect=temp;
            }
        }
    }
    if(org_list==NULL)
    {
        org_list=(Org_list*)malloc(sizeof(Org_list));
        org_list->present=key;
        org_list->next=NULL;
    }
    else{
        Org_list* temp=(Org_list*)malloc(sizeof(Org_list));
        temp->present=key;
        temp->next=org_list;
        org_list=temp;
    }
    printf("Node Created\n");
    return(key);
}
Group* create_Group()
{
    Group* key=(Group*)malloc(sizeof(Group));  int idd; char namee[100],creaton[100];
    key->indi_connect=NULL; key->busi_connect=NULL;
    printf("ID: %d\n",NUM);
    printf("Name: "); scanf(" %[^\n]s",namee);
    printf("Creation Date : "); scanf("%s",creaton);
    key->basic_info=create_Node(namee,creaton); 
    int opt;
    printf("Linked to?\n1> None 2>Business\n Any other key corresponds to none : ");
    scanf("%d",&opt);
    if(opt==2)
    {
        printf("Bussiness Id? "); scanf("%d",&idd);
        Busi* pt=search_id_busi(idd);
        if(pt==NULL) printf("key Not Found\n");
        if(pt!=NULL) 
        {
            if(key->busi_connect==NULL) {
                key->busi_connect=(Busi_conn_link*)malloc(sizeof(Busi_conn_link));
                key->busi_connect->conn = pt; 
                key->busi_connect->next=NULL;
            }
                else
            {
                Busi_conn_link* temp=(Busi_conn_link*)malloc(sizeof(Busi_conn_link));
                temp->conn=pt;
                temp->next=key->busi_connect;
                key->busi_connect=temp;
            }
            if(pt->group_connect==NULL) {
                pt->group_connect=(Group_conn_link*)malloc(sizeof(Group_conn_link));
                pt->group_connect->conn=key; 
                pt->group_connect->next=NULL;
            }
            else{
                Group_conn_link* temp=(Group_conn_link*)malloc(sizeof(Group_conn_link));
                temp->conn=key;
                temp->next=pt->group_connect;
                pt->group_connect=temp;
            }
        }
    } int no;
    printf("Number of Individuals connected : "); scanf("%d",&no); if(no>0) printf("Enter Id of the Individuals : ");
    for(int i=0;i<no;i++)
    {
        printf("%d> ",i+1); scanf("%d",&idd);
        Indi* pt=search_id_indi(idd);
        if(pt==NULL) {printf("Key Not Found\n"); continue;}
        if(pt!=NULL)
        {
            if(key->indi_connect==NULL) {
                key->indi_connect=(Indi_conn_link*)malloc(sizeof(Indi_conn_link));
                key->indi_connect->conn=pt;
                key->indi_connect->next=NULL;
            }
            else
            {
                Indi_conn_link* temp=(Indi_conn_link*)malloc(sizeof(Indi_conn_link));
                temp->conn=pt;
                temp->next=key->indi_connect;
                key->indi_connect=temp;
            } 
            if(pt->group_connect==NULL) { 
                pt->group_connect=(Group_conn_link*)malloc(sizeof(Group_conn_link));
                pt->group_connect->conn=key; 
                pt->group_connect->next=NULL;
            }
            else{
                Group_conn_link* temp=(Group_conn_link*)malloc(sizeof(Group_conn_link));
                temp->conn=key;
                temp->next=pt->group_connect;
                pt->group_connect=temp;
            }
        }
    }
    printf("Nodes Linked to each other.\n");
    if(group_list==NULL)
    {
        group_list=(Group_list*)malloc(sizeof(Group_list));
        group_list->present=key;
        group_list->next=NULL;
    }
    else{
        Group_list* temp=(Group_list*)malloc(sizeof(Group_list));
        temp->present=key;
        temp->next=group_list;
        group_list=temp;
    }
    printf("Node Created\n");
    return(key);
}

void create()
{
    printf("Enter the type of node \n");
    printf("1>Individual 2>Bussiness 3>Group 4>Organisation : ");
    int opt; scanf("%d",&opt);
    while(opt<1 || opt>4)
    {
        printf("Please choose between 1-4: ");
        scanf("%d",&opt);
    }
    if(opt==1) create_Indi(); else if(opt==2) create_Busi(); else if(opt==3) create_Group(); else create_Org();
}


// Deleting Nodes 
void delete_indi(Indi* ind)
{
    Busi_list* pt1=busi_list; int flag=0;
    while(pt1!=NULL)
    {
        Indi_conn_link* ptr=pt1->present->indi_connect;
        if(ptr!=NULL)
        {{
            while(ptr->next!=NULL)
            {
                if(ptr->next->conn==ind) 
                {ptr->next=ptr->next->next; flag=1; break;}
                ptr=ptr->next;
            }
        }
        if(ptr->conn==ind) 
        {
            ptr=NULL; free(ptr); pt1->present->indi_connect=NULL;
        }
        }
        if(flag==1) break;
        pt1=pt1->next;
    } flag=0;
    Group_list* pt2=group_list;
    while(pt2!=NULL)
    {
        Indi_conn_link* ptr=pt2->present->indi_connect;
        if(ptr!=NULL)
        {while(ptr->next!=NULL)
        {
            if(ptr->next->conn==ind) 
            {ptr->next=ptr->next->next; flag=1; break;}
            ptr=ptr->next;
            
        }
        if(ptr->conn==ind) {ptr=NULL; free(ptr); pt2->present->indi_connect=NULL;}
        }
        if(flag==1) break;
        pt2=pt2->next;
    } flag=0;
    Org_list* pt3=org_list;
    while(pt3!=NULL)
    {
        Indi_conn_link* ptr=pt3->present->indi_connect;
        if(ptr!=NULL)
        {while(ptr->next!=NULL)
        {
            if(ptr->next->conn==ind) 
            {ptr->next=ptr->next->next; flag=1; break;}
            ptr=ptr->next;
        }
        if(ptr->conn==ind) {ptr=NULL; free(ptr); pt3->present->indi_connect=NULL;}
        }
        
        if(flag==1) break;
        pt3=pt3->next;
    }
    Indi_list* pt4=indi_list,*pt;
    if(pt4==NULL) return;
    while(pt4->next!=NULL)
    {
        if(pt4->next->present==ind) 
        {pt=pt4->next; pt4->next=pt->next; pt->next=NULL; pt=NULL; free(pt); break;}
        pt4=pt4->next;
    }
    if(pt4->present==ind) {pt4=NULL; free(pt4); indi_list=NULL;}
    printf("Node Deleted\n");
}
void delete_busi(Busi* bus)
{
    Indi_list* pt1=indi_list; int flag=0;
    while(pt1!=NULL)
    {
        Busi_conn_link* ptr=pt1->present->busi_connect;
        if(ptr!=NULL)
        while(ptr->next!=NULL)
        {
            if(ptr->next->conn==bus) 
            {ptr->next=ptr->next->next; flag=1; break;}
            ptr=ptr->next;
        }
        if(flag==1) break;
        if(ptr!=NULL) if(ptr->conn==bus) {ptr=NULL; ptr=pt1->present->busi_connect=NULL;}
        pt1=pt1->next;
    } flag=0;
    Group_list* pt2=group_list;
    while(pt2!=NULL)
    {
        Busi_conn_link* ptr=pt2->present->busi_connect;
        if(ptr!=NULL)
        while(ptr->next!=NULL)
        {
            if(ptr->next->conn==bus) 
            {ptr->next=ptr->next->next; flag=1; break;}
            ptr=ptr->next;
        }
        if(flag==1) break;
        if(ptr!=NULL) if(ptr->conn==bus) {ptr=NULL; pt2->present->busi_connect=NULL;}
        pt2=pt2->next;
    }
    Busi_list* pt3=busi_list,*pt;
    if(pt3==NULL) return;
    while(pt3->next!=NULL)
    {
        if(pt3->next->present==bus) {pt=pt3->next; pt3->next=pt->next; pt->next=NULL; free(pt); break;}
        pt3=pt3->next;
    }
    if(pt3->present==bus) {pt=pt3; pt3=NULL; free(pt);}
    printf("Node Deleted\n");
}
void delete_org(Org* orga)
{
    Indi_list* pt1=indi_list; int flag=0;
    while(pt1!=NULL)
    {
        Org_conn_link* ptr=pt1->present->org_connect;
        if(ptr!=NULL)
        while(ptr->next!=NULL)
        {
            if(ptr->next->conn==orga)
            {ptr->next=ptr->next->next; flag=1; break;}
            ptr=ptr->next;
        }
        if(flag==1) break;
        if(ptr!=NULL) if(ptr->conn==orga) {ptr=NULL; free(ptr); pt1->present->org_connect=NULL;}
        pt1=pt1->next;
    }
    Org_list* pt2=org_list,*pt;
    if(pt2==NULL) return;
    while(pt2->next!=NULL)
    {
        if(pt2->next->present==orga) {pt=pt2->next; pt2->next=pt->next; pt->next=NULL; free(pt); break;}
        pt2=pt2->next;
    }
    if(pt2->present==orga) {pt=pt2; pt2=NULL; free(pt);}
    printf("Node Deleted\n");
}
void delete_group(Group* grp)
{
    Indi_list* pt1=indi_list; int flag=0;
    while(pt1!=NULL)
    {
        Group_conn_link* ptr=pt1->present->group_connect;
        if(ptr!=NULL)
        while(ptr->next!=NULL)
        {
            if(ptr->next->conn==grp) 
            {ptr->next=ptr->next->next; flag=1; break;}
            ptr=ptr->next;
        }
        if(flag==1) break;
        if(ptr!=NULL) if(ptr->conn==grp) {ptr=NULL; pt1->present->group_connect=NULL;}
        pt1=pt1->next;
    } flag=0;
    Busi_list* pt2=busi_list;
    while(pt2!=NULL)
    {
        Group_conn_link* ptr=pt2->present->group_connect;
        if(ptr!=NULL)
        while(ptr->next!=NULL)
        {
            if(ptr->next->conn==grp) 
            {ptr->next=ptr->next->next; flag=1; break;}
            ptr=ptr->next;
        }
        if(flag==1) break;
        if(ptr!=NULL) if(ptr->conn==grp) {ptr=NULL;pt2->present->group_connect=NULL;}
        pt2=pt2->next;
    }
    Group_list* pt3=group_list,*pt;
    if(pt3==NULL) return;
    while(pt3->next!=NULL)
    {
        if(pt3->next->present==grp) {pt=pt3->next; pt3->next=pt->next; pt->next=NULL; free(pt); break;}
        pt3=pt3->next;
    }
    if(pt3->present==grp) {pt=pt3; pt3=NULL; free(pt);}
    printf("Node Deleted\n");
}

void deletee()
{
    printf("To Delete "); int idd=search(); int i=0;
    Indi* ind=search_id_indi(idd); Busi* bus=search_id_busi(idd); 
    Group* grp=search_id_group(idd); Org* orgi=search_id_org(idd);
    if(ind!=NULL) {delete_indi(ind); i++;}
    if(bus!=NULL) {delete_busi(bus); i++;}
    if(grp!=NULL) {delete_group(grp); i++;}
    if(orgi!=NULL) {delete_org(orgi); i++;}
    if(i==0)
    {
        printf("No Node With Given Id Found\n"); return;
    }
}

// Printing all 1-hop linked nodes to a given input node
void one_hop_indi(Indi* ind)
{
    Busi_conn_link* pt1=ind->busi_connect; int i=0;
    while(pt1!=NULL)
    {
        show_busi(pt1->conn); printf("\n"); i++;
        pt1=pt1->next;
    }
    Group_conn_link* pt2=ind->group_connect;
    while(pt2!=NULL)
    {
        show_group(pt2->conn); printf("\n"); i++;
        pt2=pt2->next;
    }
    Org_conn_link* pt3=ind->org_connect;
    while(pt1!=NULL)
    {
        show_org(pt3->conn); printf("\n"); i++;
        pt3=pt3->next;
    }
    if(i==0)
    {
        printf("No Node connected to Given Node\n"); return;
    }
}
void one_hop_busi(Busi* bus)
{
    Indi_conn_link* pt1=bus->indi_connect; int i=0;
    while(pt1!=NULL)
    {
        show_indi(pt1->conn); printf("\n"); i++;
        pt1=pt1->next;
    }
    Group_conn_link* pt2=bus->group_connect;
    while(pt2!=NULL)
    {
        show_group(pt2->conn); printf("\n"); i++;
        pt2=pt2->next;
    }
    if(i==0)
    {
        printf("No Node connected to Given Node\n"); return;
    }
}
void one_hop_group(Group* grp)
{
    Busi_conn_link* pt1=grp->busi_connect; int i=0;
    while(pt1!=NULL)
    {
        show_busi(pt1->conn); printf("\n"); i++;
        pt1=pt1->next;
    }
    Indi_conn_link* pt2=grp->indi_connect;
    while(pt2!=NULL)
    {
        show_indi(pt2->conn); printf("\n"); i++;
        pt2=pt2->next;
    }
    if(i==0)
    {
        printf("No Node connected to Given Node\n"); return;
    }
}
void one_hop_org(Org* orga)
{
    Indi_conn_link* pt1=orga->indi_connect;
    if(pt1==NULL)
    {
        printf("No Node connected to Given Node\n"); return;
    }
    while(pt1!=NULL)
    {
        show_indi(pt1->conn); printf("\n");
        pt1=pt1->next;
    }
}

void one_hop()
{
    printf("For one Hop: "); int idd=search();
    Indi* ind=search_id_indi(idd); Busi* bus=search_id_busi(idd); 
    Group* grp=search_id_group(idd); Org* orgi=search_id_org(idd); int i=0;
    if(ind!=NULL) {one_hop_indi(ind); i++;}
    if(bus!=NULL) {one_hop_busi(bus); i++;}
    if(grp!=NULL) {one_hop_group(grp); i++;}
    if(orgi!=NULL) {one_hop_org(orgi); i++;}
    if(i==0) printf("No Node With Given Id Found\n");
}

// Creating and posting content by a node 
void create_post_Now(Node* key)
{
    if(key==NULL)
    {
        printf("Node Doesnt Exist\n"); return;
    }
    char str[100];
    printf("Write Post: "); scanf(" %[^\n]s",str);
    if(key->content==NULL)
    {
        key->content=(post_link*)malloc(sizeof(post_link));
        strcpy(key->content->post,str); 
        key->content->next=NULL;
        return;
    }
    post_link * ptr=(post_link*)malloc(sizeof(post_link));
    strcpy(ptr->post,str);
    ptr->next=key->content;
    key->content=ptr;
    printf("Content Posted \n");
}
void create_post()
{
    printf("To create post: "); int idd=search(); char j[10];
    Indi* ind=search_id_indi(idd); Busi* bus=search_id_busi(idd); 
    Group* grp=search_id_group(idd); Org* orgi=search_id_org(idd); int i=0;
    if(ind!=NULL) {create_post_Now(ind->basic_info); i++;}
    if(bus!=NULL) {create_post_Now(bus->basic_info); i++;}
    if(grp!=NULL) {create_post_Now(grp->basic_info); i++;}
    if(orgi!=NULL) {create_post_Now(orgi->basic_info); i++;}
    if(i==0) {return;}
    printf("Do you want to Show all the posts from this account? (Yes\\No)"); 
    scanf("%s",j);
    if(j[0]=='Y' || j[0]=='y')
    {
        if(ind!=NULL) show_posts(ind->basic_info);
        if(bus!=NULL) show_posts(ind->basic_info);
        if(grp!=NULL) show_posts(ind->basic_info);
        if(orgi!=NULL) show_posts(ind->basic_info);
    }
}

// Searching for a content posted by a node
void search_content()
{
    char str[100];
    printf("Enter Substring of the content : "); scanf(" %[^\n]s",str);
    int i=0;
    Indi_list* pt1=indi_list;
    while(pt1!=NULL)
    {
        post_link* ptr=pt1->present->basic_info->content;
        while(ptr!=NULL)
        {
            if(strstr(ptr->post,str))
            {
                printf("%d> Posted By\n",++i);
                printf(" ID : %d\n",pt1->present->basic_info->id);
                printf(" Name : %s\n",pt1->present->basic_info->name);
                printf("--> %s\n",ptr->post);
            }
            ptr=ptr->next;
        }
        pt1=pt1->next;
    }
    Busi_list* pt2=busi_list;
    while(pt2!=NULL)
    {
        post_link* ptr=pt2->present->basic_info->content;
        while(ptr!=NULL)
        {
            if(strstr(ptr->post,str))
            {
                printf("%d> Posted By\n",++i);
                printf(" ID : %d\n",pt2->present->basic_info->id);
                printf(" Name : %s\n",pt2->present->basic_info->name);
                printf("--> %s\n",ptr->post);
            }
            ptr=ptr->next;
        }
        pt2=pt2->next;
    }
    Group_list* pt3=group_list; 
    while(pt3!=NULL)
    {
        post_link* ptr=pt3->present->basic_info->content;
        while(ptr!=NULL)
        {
            if(strstr(ptr->post,str))
            {
                printf("%d> Posted By\n",++i);
                printf(" ID : %d\n",pt3->present->basic_info->id);
                printf(" Name : %s\n",pt3->present->basic_info->name);
                printf("--> %s\n",ptr->post);
            }
            ptr=ptr->next;
        }
        pt3=pt3->next;
    }
    Org_list* pt4=org_list;
    while(pt4!=NULL)
    {
        post_link* ptr=pt4->present->basic_info->content;
        while(ptr!=NULL)
        {
            if(strstr(ptr->post,str))
            {
                printf("%d> Posted By\n",++i);
                printf(" ID : %d\n",pt4->present->basic_info->id);
                printf(" Name : %s\n",pt4->present->basic_info->name);
                printf("--> %s\n",ptr->post);
            }
            ptr=ptr->next;
        }
        pt4=pt4->next;
    }
    if(i==0)
    printf("No Posts with give string as a substring found\n");
} 


// Displaying all content posted by nodes linked to a given node
void show_link_post_indi(Indi* ind)
{
    int i=0;
    Group_conn_link* pt2=ind->group_connect;
    printf("Linked Through Common Group : \n");
    while(pt2!=NULL)
    {
        Indi_conn_link* ptr=pt2->conn->indi_connect;
        while(ptr!=NULL)
        {
            if(ptr->conn==ind) {ptr=ptr->next; continue;}
            printf("%d> ID : %d\n",++i,ptr->conn->basic_info->id);
            printf("Name : %s\n",ptr->conn->basic_info->name);
            show_posts(ptr->conn->basic_info); printf("\n");
            ptr=ptr->next;
        }
        pt2=pt2->next;
    }
    if(i==0) printf("No Posts to Show\n"); i=0;
    Org_conn_link* pt3=ind->org_connect;
    printf("Linked Through Common Organisation : \n");
    while(pt3!=NULL)
    {
        Indi_conn_link* ptr=pt3->conn->indi_connect;
        while(ptr!=NULL)
        {
            if(ptr->conn==ind) {ptr=ptr->next; continue;}
            printf("%d> ID : %d\n",++i,ptr->conn->basic_info->id);
            printf("Name : %s\n",ptr->conn->basic_info->name);
            show_posts(ptr->conn->basic_info); printf("\n");
            ptr=ptr->next;
        }
        pt3=pt3->next;
    }
    if(i==0) printf("No Posts to Show\n");
}

void show_link_post()
{
    int idd;
    printf("Enter the ID of the Individual Node : "); scanf("%d",&idd);
    Indi* ind=search_id_indi(idd);
    if(ind!=NULL) {show_link_post_indi(ind);}
    else{
        printf("Couldnt Find an Individual Node with given Id :(\n");
    }
}

// Linking Nodes After Connection

void link_indi_busi()
{
    int idd;
    printf("Enter the ID of the Individual Node : "); scanf("%d",&idd);
    Indi* ind=search_id_indi(idd); 
    while(ind==NULL)
    {
        printf("Given Id Not Found.\n Try Another ID. Press -1 to terminate request\n");
        if(idd==-1) return;
        scanf("%d",&idd);
        ind=search_id_indi(idd);
    }
    printf("Enter the ID of the Business Node : "); scanf("%d",&idd);
    Busi* bus=search_id_busi(idd);
    while(bus==NULL)
    {
        printf("Given Id Not Found.\n Try Another ID. Press -1 to terminate request\n");
        if(idd==-1) return;
        scanf("%d",&idd);
        bus=search_id_busi(idd);
    }
    if(ind->busi_connect==NULL)
    {
        ind->busi_connect=(Busi_conn_link*)malloc(sizeof(Busi_conn_link));
        ind->busi_connect->conn=bus;
        ind->busi_connect->next=NULL;
    }
    else{
        Busi_conn_link* temp=(Busi_conn_link*)malloc(sizeof(Busi_conn_link));
        temp->conn=bus; temp->next=ind->busi_connect; ind->busi_connect=temp;
    }
    if(bus->indi_connect==NULL)
    {
        bus->indi_connect=(Indi_conn_link*)malloc(sizeof(Indi_conn_link));
        bus->indi_connect->conn=ind;
        bus->indi_connect->next=NULL;
    }
    else{
        Indi_conn_link* temp=(Indi_conn_link*)malloc(sizeof(Indi_conn_link));
        temp->conn=ind; temp->next=bus->indi_connect; bus->indi_connect=temp;
    }
    printf("Nodes Linked To Each Other\n");
}
void link_indi_group()
{
    int idd;
    printf("Enter the ID of the Individual Node : "); scanf("%d",&idd);
    Indi* ind=search_id_indi(idd);
    while(ind==NULL)
    {
        printf("Given Id Not Found.\n Try Another ID. Press -1 to terminate request\n");
        if(idd==-1) return;
        scanf("%d",&idd);
        ind=search_id_indi(idd);
    }
    printf("Enter the ID of the Group Node : "); scanf("%d",&idd);
    Group* grp=search_id_group(idd);
    while(grp==NULL)
    {
        printf("Given Id Not Found.\n Try Another ID. Press -1 to terminate request\n");
        if(idd==-1) return;
        scanf("%d",&idd);
        grp=search_id_group(idd);
    }
    if(ind->group_connect==NULL)
    {
        ind->group_connect=(Group_conn_link*)malloc(sizeof(Group_conn_link));
        ind->group_connect->conn=grp;
        ind->group_connect->next=NULL;
    }
    else{
        Group_conn_link* temp=(Group_conn_link*)malloc(sizeof(Group_conn_link));
        temp->conn=grp; temp->next=ind->group_connect; ind->group_connect=temp;
    }
    if(grp->indi_connect==NULL)
    {
        grp->indi_connect=(Indi_conn_link*)malloc(sizeof(Indi_conn_link));
        grp->indi_connect->conn=ind;
        grp->indi_connect->next=NULL;
    }
    else{
        Indi_conn_link* temp=(Indi_conn_link*)malloc(sizeof(Indi_conn_link));
        temp->conn=ind; temp->next=grp->indi_connect; grp->indi_connect=temp;
    }
    printf("Nodes Linked To Each Other\n");
}
void link_indi_org()
{
    int idd;
    printf("Enter the ID of the Individual Node : "); scanf("%d",&idd);
    Indi* ind=search_id_indi(idd);
    while(ind==NULL)
    {
        printf("Given Id Not Found.\n Try Another ID. Press -1 to terminate request\n");
        if(idd==-1) return;
        scanf("%d",&idd);
        ind=search_id_indi(idd);
    }
    printf("Enter the ID of the Organisation Node : "); scanf("%d",&idd);
    Org* orga=search_id_org(idd);
    while(orga==NULL)
    {
        printf("Given Id Not Found.\n Try Another ID. Press -1 to terminate request\n");
        if(idd==-1) return;
        scanf("%d",&idd);
        orga=search_id_org(idd);
    }
    if(ind->org_connect==NULL)
    {
        ind->org_connect=(Org_conn_link*)malloc(sizeof(Org_conn_link));
        ind->org_connect->conn=orga;
        ind->org_connect->next=NULL;
    }
    else{
        Org_conn_link* temp=(Org_conn_link*)malloc(sizeof(Org_conn_link));
        temp->conn=orga; temp->next=ind->org_connect; ind->org_connect=temp;
    }
    if(orga->indi_connect==NULL)
    {
        orga->indi_connect=(Indi_conn_link*)malloc(sizeof(Indi_conn_link));
        orga->indi_connect->conn=ind;
        orga->indi_connect->next=NULL;
    }
    else{
        Indi_conn_link* temp=(Indi_conn_link*)malloc(sizeof(Indi_conn_link));
        temp->conn=ind; temp->next=orga->indi_connect; orga->indi_connect=temp;
    }
    printf("Nodes Linked To Each Other\n");
}
void link_busi_group()
{
    int idd;
    printf("Enter the ID of the Individual Node : "); scanf("%d",&idd);
    Busi* bus=search_id_busi(idd);
    if(bus==NULL)
    {
        printf("Given Id Not Found.\n Try Another ID. Press -1 to terminate request\n");
        if(idd==-1) return;
        scanf("%d",&idd);
        bus=search_id_busi(idd);
    }
    printf("Enter the ID of the Group Node : "); scanf("%d",&idd);
    Group* grp=search_id_group(idd);
    if(grp==NULL)
    {
        printf("Given Id Not Found.\n Try Another ID. Press -1 to terminate request\n");
        if(idd==-1) return;
        scanf("%d",&idd);
        grp=search_id_group(idd);
    }
    if(grp->busi_connect==NULL)
    {
        grp->busi_connect=(Busi_conn_link*)malloc(sizeof(Busi_conn_link));
        grp->busi_connect->conn=bus;
        grp->busi_connect->next=NULL;
    }
    else{
        Busi_conn_link* temp=(Busi_conn_link*)malloc(sizeof(Busi_conn_link));
        temp->conn=bus; temp->next=grp->busi_connect; grp->busi_connect=temp;
    }
    if(bus->indi_connect==NULL)
    {
        bus->group_connect=(Group_conn_link*)malloc(sizeof(Group_conn_link));
        bus->group_connect->conn=grp;
        bus->group_connect->next=NULL;
    }
    else{
        Group_conn_link* temp=(Group_conn_link*)malloc(sizeof(Group_conn_link));
        temp->conn=grp; temp->next=bus->group_connect; bus->group_connect=temp;
    }
    printf("Nodes Linked To Each Other\n");
}

void link_connect()
{
    printf("Enter the type of Link to be Made\n");
    printf("1 > Individual-Business\n");
    printf("2 > Individual-Group\n");
    printf("3 > Individual-Organisation\n");
    printf("4 > Bussiness-Group\n");
    int opt; scanf("%d",&opt);
    while(opt<1 || opt>4)
    {
        printf("Please enter a valid option: "); scanf("%d",&opt);
    }
    if(opt==1) link_indi_busi();
    if(opt==2) link_indi_group();
    if(opt==3) link_indi_org();
    if(opt==4) link_busi_group();
}

// Showing all The Nodes in the Network

void show_all()
{
    int i=0;
    printf("Individual Nodes: \n");
    Indi_list* pt1=indi_list;
    while(pt1!=NULL)
    {
        printf("%d> ",i+1); i++;
        show_indi(pt1->present); printf("\n");
        pt1=pt1->next;
    }
    printf("Business Nodes: \n");
    Busi_list* pt2=busi_list;
    while(pt2!=NULL)
    {
        printf("%d> ",i+1); i++;
        show_busi(pt2->present); printf("\n");
        pt2=pt2->next;
    }
    printf("Group Nodes: \n");
    Group_list* pt3=group_list; 
    while(pt3!=NULL)
    {
        printf("%d> ",i+1); i++;
        show_group(pt3->present); printf("\n");
        pt3=pt3->next;
    }
    printf("Organisation Nodes: \n");
    Org_list* pt4=org_list;
    while(pt4!=NULL)
    {
        printf("%d> ",i+1); i++;
        show_org(pt4->present); printf("\n");
        pt4=pt4->next;
    }
}

// Show all contents posted by a Node

void show_post()
{
    printf("To show posts of a given Node : \n"); int idd=search();
    Indi* ind=search_id_indi(idd); Busi* bus=search_id_busi(idd); 
    Group* grp=search_id_group(idd); Org* orgi=search_id_org(idd); int i=0;
    if(ind!=NULL) {show_posts(ind->basic_info); i++;}
    if(bus!=NULL) {show_posts(bus->basic_info); i++;}
    if(grp!=NULL) {show_posts(grp->basic_info); i++;}
    if(orgi!=NULL) {show_posts(orgi->basic_info); i++;}
    if(i==0)
    {
        printf("Cannot Show Posts Because Id Not Found :(\n");
    }
}

// A master text-based interface to print all nodes in the system and utilize all the above functionalities

void give_options()
{
    begin();
    int opt; printf("Print -1 to exit\n");
    printf("1>Create a New Node\t");
    printf("2> Delete a node\n");
    printf("3> Search for a node\n");
    printf("4> Print all 1-hop linked nodes to a given input node.\n");
    printf("5> Create and Post content by any node\n");
    printf("6> Search for content posted by any node\n");
    printf("7> Display all content posted by nodes linked to a given node.\n");
    printf("8> Link Nodes between Each Other\n");
    printf("9> Show all Nodes\n");
    printf("10> Show all the Contents Posted by a given Node\n");
    printf("Please enter keys with Valid options\nPress 0 to review Your options\n");
    do{
        scanf("%d",&opt);
        while(opt<-1 || opt>10)
        {
            printf("Please enter keys with Valid options\nPress 0 to review Your options\n");
            scanf("%d",&opt);
        }
        if(opt==0)
        {
            printf("1>Create a New Node\t");
            printf("2> Delete a node\n");
            printf("3> Search for a node\n");
            printf("4> Print all 1-hop linked nodes to a given input node.\n");
            printf("5> Create and Post content by any node\n");
            printf("6> Search for content posted by any node\n");
            printf("7> Display all content posted by nodes linked to a given node.\n");
            printf("8> Link Nodes between Each Other\n");
            printf("9> Show all Nodes\n");
            printf("10> Show all the Contents Posted by a given Node\n");
        }
        else if(opt==1) create();
        else if(opt==2) deletee();
        else if(opt==3) Actual_search();
        else if(opt==4) one_hop();
        else if(opt==5) create_post();
        else if(opt==6) search_content();
        else if(opt==7)show_link_post();
        if(opt==8) link_connect();
        if(opt==9) show_all();
        if(opt==10) show_post();
        if(opt==-1) break;
        printf("Press -1 to exit program, press 0 to review options\n");
    }while(opt!=-1);
}

// Main Function
int main()
{
    give_options();
}
