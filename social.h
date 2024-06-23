// NAME : ANKITA MISHRA
// ROLL NO.: 22CS10010
// ****************************************DOCUMENTATION***********************************************
//              ASSUMPTIONS: 1> Name cannot be more than 100 characters
//                           2> BirthDate and creation Date cannot be more than 100 characters
//                             CODE STRUCTURE:
// 1> struct temps are temporary names changed as soon as defined, the typedefed names are used for the rest of the code
// 2> Basic node structure is made for all kinds of nodes, contains basic info like name,id creation date
// 3> For additional info, type specific nodes are made containing basic node as one of its component
// 4> Contents of each node are connected through a separate linked list of type "post_link"
// 5> Four Global Variables are declared for each four type of nodes, those variables also in linked list form,
//    list containing list of all nodes of a particular type(Indi_list, Busi_list, Org_list, Group_list)
// 6> One Global variable NUM(int type) is declared to assign id to each new node
// 7> For connecting nodes of Different type,Separated Linked lists are made, such as, Indi_conn_list is a 
//    linked list that stores individual node connection in groups, business and organisation nodes
//                              FUNCTIONS:
// 1> Create Node creates basic info like name and creation Date
// 2> Specific Info's like birthday and Location is strored while creating specific type nodes 
//    in functions like create_indi, create_org, etc.
// 3> Functions Like show_indi, show_busi shows the details of type specific nodes
// 4> Working of search Function: User is asked whether to search by name, id, type or Birthday
//    User types the preference and the info related, and it is sent to the function search_by_name, 
//    if name type is searched, search_by_id, if id type and so on
//    All search_by functions returns the id of the given node(if multiples matches found, user is asked to choose which one)
//    The id is sent to other set of functions(search_id_indi,search_id_busi,etc.) and node found is returned
//    Rest operations are done on the found node
// 5> Working of Actual_search function: Most Things are same with search function except it returns nothing, 
//    it just shows all the nodes which matches with the search by user
// 6> Delete Functions: Functions like delete_indi() first searches for the given node in any connections of 
//    other type nodes such as connections of business nodes, and break the link without loss of other links.
//    At last, it deletes the node completely for indi_list
// 7> One-Hop Functions: We take user from input and find the target node and search through all the connections 
//    of the target node and show their infos
// 8> Create and Post Content: We take the target node and from the user and also the content string, 
//    we link the string to the first of linked list of post of that node and add the rest to its tail
// 9> Link_connect function: Links between busi-indi, group-indi, org-indi, group-busi can be made later also using 
//    the same process used in create node Function
// 10> Show_link_post Function:  Shows contents posted by all indi nodes related 
//     to the given indi node by common group or organisation
//                      Indi-Individual, Busi-Business, Org-Organisation
// **********************************End of Documnetation**********************************************

struct temp0{
    int x;
    int y;
}; typedef struct temp0 pair;

struct temp1{
    char post[1000];
    struct temp1* next;
}; typedef struct temp1 post_link;

// Basic Info

struct tempo{
    int id;
    char name[100];
    char creation[100];
    post_link* content;
}; typedef struct tempo Node;

// Connection Link For Each Class
struct temp6;
struct temp7;
struct temp8;
struct temp9;

struct temp2{
    struct temp6* conn;
    struct temp2* next;
}; typedef struct temp2 Indi_conn_link;
struct temp3{
    struct temp7* conn;
    struct temp3* next;
}; typedef struct temp3 Busi_conn_link;
struct temp4{
    struct temp8* conn;
    struct temp4* next;
}; typedef struct temp4 Org_conn_link;
struct temp5{
    struct temp9* conn;
    struct temp5* next;
}; typedef struct temp5 Group_conn_link;

// Ultimate Struct of Each Type
struct temp6
{
    Node* basic_info;
    char birth[100]; // optional
    Busi_conn_link* busi_connect;
    Org_conn_link* org_connect;
    Group_conn_link* group_connect;
}; typedef struct temp6 Indi;
struct temp7
{
    Node* basic_info;
    pair location;
    Indi_conn_link* indi_connect;
    Group_conn_link* group_connect;
}; typedef struct temp7 Busi;
struct temp8
{
    Node* basic_info;
    pair location;
    Indi_conn_link* indi_connect;
}; typedef struct temp8 Org;
struct temp9
{
    Node* basic_info;
    Indi_conn_link* indi_connect;
    Busi_conn_link* busi_connect;
}; typedef struct temp9 Group;

// For Ultimate Type Wise List!
struct temp10
{
    Indi* present;
    struct temp10* next;
}; typedef struct temp10 Indi_list;
struct temp11
{
    Busi* present;
    struct temp11* next;
}; typedef struct temp11 Busi_list;
struct temp12
{
    Org* present;
    struct temp12* next;
}; typedef struct temp12  Org_list;
struct temp13
{
    Group* present;
    struct temp13* next;
}; typedef struct temp13 Group_list;
void show_basic(Node* key);
void show_posts(Node* key);
void show_indi(Indi* ind);
void show_busi(Busi* bus);
void show_org(Org* orga);
void show_group(Group* grp);
Indi* search_id_indi(int idd);
Busi* search_id_busi(int idd);
Org* search_id_org(int idd);
Group* search_id_group(int idd);
int search_by_name();
int search_by_id();
int search_by_birthday();
int search_by_type();
int search();
void actual_search_by_name();
void actual_search_by_id();
void actual_search_by_birthday();
void actual_search_by_type();
void Actual_search();
Node* create_Node(char namee[],char creaton[]);
Indi* create_Indi();
Busi* create_Busi();
Org*  create_Org();
Group* create_Group();
void create();
void delete_indi(Indi* ind);
void delete_busi(Busi* bus);
void delete_org(Org* orga);
void delete_group(Group* grp);
void deletee();
void one_hop_indi(Indi* ind);
void one_hop_busi(Busi* bus);
void one_hop_group(Group* grp);
void one_hop_org(Org* orga);
void one_hop();
void create_post_Now(Node* key);
void create_post();
void show_post();
void show_link_post_indi(Indi* ind);
void show_link_post();
void link_indi_busi();
void link_indi_group();
void link_indi_org();
void link_busi_group();
void link_connect();
void show_all();
void give_options();
int main();