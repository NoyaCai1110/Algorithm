#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>
#include <fstream>

using namespace std;
ofstream out("FTree.txt", ios::out);


typedef struct _FamilyNode
{
    struct _FamilyNode* parent;
    struct _FamilyNode* r_sibling;
    struct _FamilyNode* firstchild;
    char name[30] = {'\0'};
    char s_name[30] = {'\0'};
} FamilyNode;

FamilyNode* find(FamilyNode *T,char b[20])
{
	if(T){
        if((strcmp(T->name,b)==0) || (strcmp(T->s_name,b)==0))
        {
            return T;
        }
        else{
            if(find(T->firstchild, b))
                return find(T->firstchild, b);
            if(find(T->r_sibling, b))
                return find(T->r_sibling, b);
        }
    }
    return nullptr;
}

void insert_sibling(FamilyNode *P, FamilyNode *T){
    if(P->firstchild != nullptr){
        P = P->firstchild;
        //cout << "flag31" << endl; 
        while(P->r_sibling != nullptr){
            //cout << "flag" << endl;
            P = P->r_sibling;
        }
        //cout << "flag32" << endl;
        P->r_sibling = T;
        //cout << "flag33" << endl;
    }
    else{
        P->firstchild = T;
    }
}

int cal_generation(FamilyNode *T, FamilyNode *P){
    int cnt = 0;
    while(T != P){
        T = T->parent;
        cnt ++;
    }
    return cnt;
}

void printtree(FamilyNode *T, FamilyNode *P){
    cout << T->name << "(" << T->s_name << ")" << endl;
    if(T->firstchild != nullptr){
        int cnt = cal_generation(T->firstchild, P);
        for(int i = 0; i < cnt; i ++){
            cout << "--";
        }
        printtree(T->firstchild, P);
    }
    if(T->r_sibling != nullptr){
        int cnt = cal_generation(T->r_sibling, P);
        for(int i = 0; i < cnt; i ++){
            cout << "--";
        }
        printtree(T->r_sibling, P);
    }
}

void savetree(FamilyNode *T, FamilyNode *P){
    out << T->name << "(" << T->s_name << ")" << endl;
    if(T->firstchild != nullptr){
        int cnt = cal_generation(T->firstchild, P);
        for(int i = 0; i < cnt; i ++){
            out << "--";
        }
        savetree(T->firstchild, P);
    }
    if(T->r_sibling != nullptr){
        int cnt = cal_generation(T->r_sibling, P);
        for(int i = 0; i < cnt; i ++){
            out << "--";
        }
        savetree(T->r_sibling, P);
    }
}

int main(){

    FamilyNode *ancestor, *tmp, *tmp1;
    ancestor = (FamilyNode*)malloc(sizeof(FamilyNode));
    ancestor->parent = nullptr;
    ancestor->r_sibling = nullptr;
    ancestor->firstchild = nullptr;
    tmp = (FamilyNode*)malloc(sizeof(FamilyNode));
    tmp1 = (FamilyNode*)malloc(sizeof(FamilyNode));
    char emp[30] = {'\0'};
    //A Add family member
    
    //B Delete family member
    FamilyNode *d_person;
    d_person = (FamilyNode*)malloc(sizeof(FamilyNode));
    d_person->parent = nullptr;
    d_person->r_sibling = nullptr;
    d_person->firstchild = nullptr;
    //C Search for family member's info
    FamilyNode *f_person, *f_parent;
    f_person = (FamilyNode*)malloc(sizeof(FamilyNode));
    f_person->parent = nullptr;
    f_person->r_sibling = nullptr;
    f_person->firstchild = nullptr;
    f_parent = (FamilyNode*)malloc(sizeof(FamilyNode));
    f_parent->parent = nullptr;
    f_parent->r_sibling = nullptr;
    f_parent->firstchild = nullptr;
    //D Print family tree members according to their seniority
    queue <FamilyNode*> q, q1;

    cout << "Welcome to the family tree system" << endl;
    cout << "Please enter ancestors' info according to the following tips" << endl;
    cout << "Name: " << endl;
    cin  >> ancestor->name;
    cout << "Spouse Name: " << endl;
    cin  >> ancestor->s_name;

    char action = 'O';
    while(action != 'Q'){
        cout << "Please enter the letter to select the corresponding operation:" << endl;
        cout << "A Add family member" << endl;
        cout << "B Delete family member" << endl;
        cout << "C Search for family member's info" << endl;
        cout << "D Print family tree members according to their seniority" << endl;
        cout << "E Print the family tree in tree structure" << endl;
        cout << "F Save family tree to file" << endl;
        cout << "Q Exit system" << endl;   
        cout << "NOTE: Please avoid entering family members with the same name!" << endl; 
        cin >> action;
        switch (action)
        {
            case 'A':{                   //A Add family member
                cout << "Please select the identity of the member to be added:" << endl;
                cout << "a Child" << endl;
                cout << "b Spouse" << endl;
                char act = 'o';
                cin >> act;
                if(act == 'a'){
                    cout <<"Please enter the name of the father (mother) of the member to be added:" << endl;
                    FamilyNode *n_parent, *n_person;
                    n_parent = (FamilyNode*)malloc(sizeof(FamilyNode));
                    n_parent->parent = nullptr;
                    n_parent->r_sibling = nullptr;
                    n_parent->firstchild = nullptr;
                    n_person = (FamilyNode*)malloc(sizeof(FamilyNode));
                    n_person->parent = nullptr;
                    n_person->r_sibling = nullptr;
                    n_person->firstchild = nullptr;
                    char new_parent[30];
                    cin >> new_parent;
                    tmp = ancestor;
                    n_parent = find(tmp, new_parent);
                    if(n_parent == nullptr){
                        cout << "The member does not exist." << endl;
                        break;
                    }
                    //cout << "flag1" << endl;
                    n_person->parent = n_parent;
                    //cout << "flag2" << endl;
                    insert_sibling(n_parent, n_person);
                    //cout << "flag3" << endl;
                    cout << "Please enter the name of the member to be added:" << endl;
                    cin >> n_person->name;
                }
                else if(act == 'b'){
                    cout <<"Please enter the name of the spouse of the member to be added(Note: If the member already has a spouse, the new spouse will replace the original):" << endl;
                    FamilyNode *n_spouse;
                    n_spouse = (FamilyNode*)malloc(sizeof(FamilyNode));
                    n_spouse->parent = nullptr;
                    n_spouse->r_sibling = nullptr;
                    n_spouse->firstchild = nullptr;
                    char sp_name[30];
                    cin >> sp_name;
                    tmp = ancestor;
                    n_spouse = find(tmp, sp_name);
                    cout << "Please enter the name of the member to be added:" << endl;
                    cin >> n_spouse->s_name; 
                }
                else{
                    cout << "The operation corresponding to this letter does not exist." << endl; 
                }
                break;
            }
            case 'B':                   //B Delete family member
                cout << "Please enter the name of the member to be deleted:" << endl;
                char d_name[30];
                cin >> d_name;
                tmp = ancestor;
                d_person = find(tmp, d_name);
                if(d_person == nullptr){
                    cout << "The member does not exist." << endl;
                    break;
                }
                else if(strcmp(d_person->name, d_name) != 0){
                    cout << d_person->name << " 's spouse has been deleted." << endl;
                    strcpy_s(d_person->s_name, emp);
                }
                else if(d_person == ancestor){
                    cout << "The ancestor can not be deleted." << endl;
                    break;
                }
                else{
                    if(d_person->parent->firstchild == d_person){
                        if(d_person->r_sibling == nullptr)
                            d_person->parent->firstchild = nullptr;
                        else{
                            d_person->parent->firstchild = d_person->r_sibling;
                            d_person->r_sibling = nullptr;
                        }
                    }
                    else{
                        tmp = d_person->parent->firstchild;
                        while(tmp->r_sibling != d_person){
                            tmp = tmp->r_sibling;
                        }
                        if(d_person->r_sibling == nullptr)
                            tmp->r_sibling = nullptr;
                        else{
                            tmp->r_sibling = d_person->r_sibling;
                            d_person->r_sibling = nullptr;
                        }
                            
                    }
                    d_person->parent = nullptr;
                }
                break;
            case 'C':{                   //C Search for family member's info
                cout << "Please enter the name of the member to be queried:" << endl;
                char f_name[30];
                cin >> f_name;
                tmp = ancestor;
                f_person = find(tmp, f_name);
                if(f_person == nullptr){
                    cout << "The member does not exist" << endl;
                    break;
                }
                //cout << tmp->name << " " << tmp->s_name << endl;
                //cout << "flag" << endl;
                if(strcmp(f_person->name, f_name) == 0){
                    if(f_person != ancestor)
                        cout << "Parent's name: " << f_person->parent->name << " " << f_person->parent->s_name << endl;
                    if(strcmp(f_person->s_name, emp) != 0)
                        cout << "Spouse's name: " << f_person->s_name << endl;
                    if(f_person != ancestor){
                        f_parent = f_person->parent;
                        tmp = f_parent->firstchild;
                        if(tmp->r_sibling == nullptr)
                            cout << "This member has no siblings." << endl;
                        else{
                            cout << "Name(s) of sibling: ";
                            if(strcmp(tmp->name, f_person->name) != 0)
                                cout << tmp->name << " ";
                            while(tmp->r_sibling != nullptr){
                                if(strcmp(tmp->r_sibling->name, f_person->name) != 0)
                                    cout << tmp->r_sibling->name << " ";
                                tmp = tmp->r_sibling;
                            }
                            cout << "" << endl;
                        }
                    }
                }
                else{
                    cout << "The member is the spouse of a member in the family tree, only spouse and descendant information is recorded." << endl;
                    cout << "Spouse's name: " << f_person->name << endl;
                }
                if(f_person->firstchild != nullptr){
                    cout << "Child(ren)'s name(s): " << f_person->firstchild->name << " ";
                    tmp = f_person->firstchild;
                    while(tmp->r_sibling != nullptr){
                        cout << tmp->r_sibling->name << " ";
                        tmp = tmp->r_sibling;
                    }
                    cout << "" << endl;
                }
                else
                    cout << "This member has no descendants." << endl;
                break;
            }
            case 'D':{                   //D Print family tree members according to their seniority
                tmp = ancestor;
                q.push(tmp);
                q1.push(tmp);
                while(!q.empty()){
                    tmp = q.front();
                    q.pop();
                    cout << tmp->name << "(" << tmp->s_name << ")   ";
                    if(tmp == q1.front()){
                        //cout << "" << endl;
                        tmp1 = q1.front();
                        int count = 0;
                        while(tmp1 != ancestor){
                            count ++;
                            tmp1 = tmp1->parent;
                        }
                        tmp1 = q1.front();
                        q1.pop();
                        cout << "------" << "Generation" << count;
                        if(count != 0){
                            cout << "[" << tmp1->parent->name << " 's child(ren)]" << endl;
                        }
                        else
                            cout << "" << endl;
                    }
                    if(tmp->firstchild != nullptr){
                        tmp = tmp->firstchild;
                        q.push(tmp);
                        while(tmp->r_sibling != nullptr){
                            q.push(tmp->r_sibling);
                            tmp = tmp->r_sibling;
                        }
                        q1.push(tmp);
                    }
                }
                break;
            }
            case 'E':{                   //E Print the family tree in tree structure
                tmp = ancestor;
                tmp1 = ancestor;
                printtree(tmp, tmp1);
                break;
            }
            case 'F':                   //F Save family tree to file
                tmp = ancestor;
                tmp1 = ancestor;
                savetree(tmp, tmp1);
                cout << "Family tree saved" << endl;
                break;
            case 'Q':                   //Q Exit system
                break;
            
            default:
                cout << "The operation corresponding to this letter does not exist." << endl;
                break;
        }
    }

    return 0;
}