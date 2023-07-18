#include<iostream>
using namespace std;

struct customerNode
{
    string customerName;
    int foodQuantity,bill,orderToken;
    customerNode *next;

}*customerHead=NULL;


struct foodNode
{
    string foodName;
    int foodPrice,foodToken;
    foodNode *next;

}*foodHead=NULL;


struct pendingFoodNode
{
    string pendingFoodName;
    int pendingFoodQuantity;
    pendingFoodNode *next;

}*pendingFoodHead=NULL;

int profit=0;

void addCustomer()
{
    customerNode* c=new customerNode;
    customerNode *x;

    cout<<"Customer User Name: ";
    cin.ignore();
    getline(cin,c->customerName);
    cout<<"Order Token: ";
    cin>>c->orderToken;
    cout<<"Food Quantity: ";
    cin>>c->foodQuantity;
    cout<<".................\n";

    c->next=NULL;

    if(customerHead==NULL){
        customerHead=c;
    }
    else{
        x=customerHead;
        while(x->next!=NULL){
            x=x->next;
        }
        x->next=c;
    }
}

void foodStroage()
{
    foodNode *currentFood,*cf;

    currentFood=new foodNode();
    currentFood->foodName="Chicken Pizza";
    currentFood->foodToken=1;
    currentFood->foodPrice=40;
    currentFood->next=NULL;
    foodHead=currentFood;

    cf=foodHead;


    currentFood=new foodNode();
    currentFood->foodName="Pepperoni Pizza";
    currentFood->foodToken=2;
    currentFood->foodPrice=80;
    currentFood->next=NULL;
    while(cf->next!=NULL){
        cf=cf->next;
    }
    cf->next=currentFood;
    cf=foodHead;

    currentFood=new foodNode();
    currentFood->foodName="Chicken Burger";
    currentFood->foodToken=3;
    currentFood->foodPrice=30;
    currentFood->next=NULL;
    while(cf->next!=NULL){
        cf=cf->next;
    }
    cf->next=currentFood;
    cf=foodHead;

    currentFood=new foodNode();
    currentFood->foodName="Beef Burger";
    currentFood->foodToken=4;
    currentFood->foodPrice=35;
    currentFood->next=NULL;
    while(cf->next!=NULL){
        cf=cf->next;
    }
    cf->next=currentFood;
    cf=foodHead;

    currentFood=new foodNode();
    currentFood->foodName="Chicken Sandwich";
    currentFood->foodToken=5;
    currentFood->foodPrice=20;
    currentFood->next=NULL;
    while(cf->next!=NULL){
        cf=cf->next;
    }
    cf->next=currentFood;
    cf=foodHead;


    currentFood=new foodNode();
    currentFood->foodName="Vegetable Sandwich";
    currentFood->foodToken=6;
    currentFood->foodPrice=20;
    currentFood->next=NULL;
    while(cf->next!=NULL){
        cf=cf->next;
    }
    cf->next=currentFood;
    cf=foodHead;

    currentFood=new foodNode();
    currentFood->foodName="Chicken fry";
    currentFood->foodToken=7;
    currentFood->foodPrice=40;
    currentFood->next=NULL;
    while(cf->next!=NULL){
        cf=cf->next;
    }
    cf->next=currentFood;
    cf=foodHead;


    currentFood=new foodNode();
    currentFood->foodName="Pepsi";
    currentFood->foodToken=8;
    currentFood->foodPrice=15;
    currentFood->next=NULL;
    while(cf->next!=NULL){
        cf=cf->next;
    }
    cf->next=currentFood;
    cf=foodHead;

    currentFood=new foodNode();
    currentFood->foodName="Coke";
    currentFood->foodToken=9;
    currentFood->foodPrice=20;
    currentFood->next=NULL;
    while(cf->next!=NULL){
        cf=cf->next;
    }
    cf->next=currentFood;
    cf=foodHead;

    currentFood=new foodNode();
    currentFood->foodName="Lemonade";
    currentFood->foodToken=10;
    currentFood->foodPrice=25;
    currentFood->next=NULL;
    while(cf->next!=NULL){
        cf=cf->next;
    }
    cf->next=currentFood;
    cf=foodHead;

    currentFood=new foodNode();
    currentFood->foodName="Tea";
    currentFood->foodToken=11;
    currentFood->foodPrice=10;
    currentFood->next=NULL;
    while(cf->next!=NULL){
        cf=cf->next;
    }
    cf->next=currentFood;
    cf=foodHead;

    currentFood=new foodNode();
    currentFood->foodName="Green Tea";
    currentFood->foodToken=12;
    currentFood->foodPrice=15;
    currentFood->next=NULL;
    while(cf->next!=NULL){
        cf=cf->next;
    }
    cf->next=currentFood;
    cf=foodHead;

    currentFood=new foodNode();
    currentFood->foodName="Hot coffee";
    currentFood->foodToken=13;
    currentFood->foodPrice=15;
    currentFood->next=NULL;
    while(cf->next!=NULL){
        cf=cf->next;
    }
    cf->next=currentFood;
    cf=foodHead;

    currentFood=new foodNode();
    currentFood->foodName="Cold coffee";
    currentFood->foodToken=14;
    currentFood->foodPrice=25;
    currentFood->next=NULL;
    while(cf->next!=NULL){
        cf=cf->next;
    }
    cf->next=currentFood;
    cf=foodHead;

    currentFood=new foodNode();
    currentFood->foodName="Water(250mL)";
    currentFood->foodToken=15;
    currentFood->foodPrice=15;
    currentFood->next=NULL;
    while(cf->next!=NULL){
        cf=cf->next;
    }
    cf->next=currentFood;
    cf=foodHead;
}

void orderedfoodProcess()
{
    foodStroage();
    customerNode *c=customerHead;
    foodNode *f;
    pendingFoodNode *pf;

    while(c!=NULL){
        f=foodHead;
        while(f!=NULL){
            if(c->orderToken==f->foodToken){
                pf=new pendingFoodNode();
                pf->pendingFoodName=f->foodName;
                pf->pendingFoodQuantity=c->foodQuantity;
                pf->next=pendingFoodHead;
                pendingFoodHead=pf;
            }
            f=f->next;
        }
        c=c->next;
    }
}

void orderedFood()
{
    orderedfoodProcess();
    pendingFoodNode *x=pendingFoodHead;

    while(x!=NULL){
        cout<<"Ordered Food: "<<x->pendingFoodName<<"............"<<"Quantity: "<<x->pendingFoodQuantity<<endl;
        x=x->next;
    }
}

void customerList()
{
    customerNode *c=customerHead;
    int i=1;

    while(c!=NULL){
        cout<<i<<"th name: "<<c->customerName<<endl;
        i++;
        c=c->next;
    }
}

void foodList()
{
    foodStroage();
    foodNode *f=foodHead;

    while(f!=NULL){
        cout<<"Food Name: "<<f->foodName<<"(Food Token: "<<f->foodToken<<")"<<endl;
        cout<<"Food Price: "<<f->foodPrice<<endl;
        cout<<"............................"<<endl;
        f=f->next;
    }
}

void income()
{
    foodStroage();
    customerNode *c=customerHead;
    foodNode *f;

    while(c!=NULL){
        f=foodHead;
        while(f!=NULL){
            if(c->orderToken==f->foodToken){
                c->bill=(f->foodPrice)*(c->foodQuantity);
                profit=profit+c->bill;
            }
            f=f->next;
        }
        c=c->next;
    }

    cout<<"Total Profit: "<<profit<<" Taka"<<endl;
    cout<<"................\n";
}

void choiceList()
{
    cout<<"\t\tPress 1 see the food list"<<endl;
    cout<<"\t\tPress 2 to add customer"<<endl;
    cout<<"\t\tPress 3 to see customer details"<<endl;
    cout<<"\t\tPress 4 to see ordered food list"<<endl;
    cout<<"\t\tPress 5 to see the profit(Taka)"<<endl;
    cout<<"\t\tPress 6 to see the choice lists"<<endl;
    cout<<"\t\tPress 0 to exit"<<endl;
    cout<<"....................\n";
}

void menu()
{
    int choice;
    string qus;

    cout<<"Hello, Mahadi's food delivery system"<<endl;
    choiceList();

    cout<<"Your Choice: ";
    cin>>choice;

    while(choice==1||choice==2||choice==3||choice==4||choice==5||choice==6){

        switch(choice)
        {
        case 1:
            foodList();
            break;
        case 2:
            addCustomer();
            break;
        case 3:
            customerList();
            break;
        case 4:
            orderedFood();
            break;
        case 5:
            income();
            break;
        case 6:
          choiceList();
          break;
        }
        cout<<"Your Choice: ";
        cin>>choice;

        if(choice==0){
            cout<<"Thanks for your co-operation"<<endl;
            break;
        }
    }
}

int main()
{
    menu();
}
