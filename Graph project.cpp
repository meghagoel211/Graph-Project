
#include<iostream>

#include<stdio.h>

#include<fstream>
#include<ctype.h>
#include<stdlib.h>
#include<iomanip>
#include<string>
#include<bits/stdc++.h>

using namespace std;

long int code;

class vertex
{
  public:
    string name;
    int status;
    int state;
    int predecessor;
    int pathlength;
    vertex ()
    {
        name = "";
    }
    vertex (string name1)
   {
       name=name1;
   }
};

static int n=0;
static int e=0;

class directedgraph
{
   public:
       int max_vertices ;

       int initial;
       int  waiting;
       int visited;
      int nil;
      long infinity;
      int temporary;
       int permanant;
      int adj[30][30] ;
      vertex vertexlist[30];
      directedgraph()
      {
          for(int i=0;i<30;i++)
          {
              for(int j=0;j<30;j++)
              {
                  adj[i][j]=-1;
              }
          }
           initial=0;
         waiting =1;
       visited =2;
      nil=-1;
   infinity=99999999;
       temporary=1;
    permanant=2;
      }
      int getindex(string s)
      {
          for(int i=0;i<=n;i++)
          {
              if(s.compare(vertexlist[i].name)==0)
                    return i;
          }
        cout<<"invalid vertex"<<endl;
        return -1;
      }
      int vertices()
      {
          return n;
      }
      int edges()
      {
          return e;
      }
      void insertvertex(string name)
      {
          n++;
          vertex p(name);
          vertexlist[n] = p;
      }
      void insertedge(string s1, string s2,int d)
      {
          int u=getindex(s1);
          int v=getindex(s2);
         // cout<<u<<" "<<v<<endl;

          if(u==v)
            cout<<"not a valid edge"<<endl;
          if(adj[u][v]!=-1)
            cout<<"edge is already present"<<endl;
          else
          {
              adj[u][v]=d;
              e++;
          }
      }
      void display()
      {
          for(int i=0;i<=n;i++)
          {
              for(int j=0;j<=n;j++)
              {
                  if(adj[i][j])
                    cout<<"1"<<" ";
                  else
                    cout<<"0"<<" ";
              }

              cout<<endl;
          }
       }

       bool isadjacent(int u,int v)
       {
           if( adj[u][v]!=-1)
               return true;
           else
            return false;
       }

       int tempvertexminpl()
       {
           int min1 = infinity;
           int x= nil;
           for(int v=0;v<=n;v++)
           {
               if(vertexlist[v].status==temporary&&vertexlist[v].pathlength<min1)
               {
                   min1=vertexlist[v].pathlength;
                   x=v;
               }
           }
           return x;

       }

       void dijkstra (int s)
       {
           int v,c;
           for(v=0;v<=n;v++)
           {
               vertexlist[v].status=temporary;
               vertexlist[v].pathlength=infinity;
               vertexlist[v].predecessor=nil;
           }

           vertexlist[s].pathlength=0;
           while(true)
           {

               c=tempvertexminpl();
               if(c==nil)
                return;

               vertexlist[c].status=permanant;

               for(v=0;v<=n;v++)
               {
                   if(isadjacent(c,v)&&vertexlist[v].status==temporary)
                      if(vertexlist[c].pathlength+adj[c][v]<vertexlist[v].pathlength)
                   {
                       vertexlist[v].predecessor=c;
                       vertexlist[v].pathlength=vertexlist[c].pathlength+adj[c][v];
                   }
               }
           }
       }

        void findpath(int s, int v,int bud)
       {
           int i, u;
           int path[70];
           int sd=0;
           int count1=0;

           while(v!=s)
           {
               count1++;
               path[count1]=v;
               u=vertexlist[v].predecessor;
               sd=sd + adj[u][v];
               v=u;
           }
           count1++;
           path[count1]=s;

       if(count1>1)
       {

        if(sd<bud)
           {
               cout<<endl;
               cout<<"Your tour is ";
               for(i=count1;i>=1;i--)
            cout<<vertexlist[path[i]].name<<"  ";
           cout<<endl;
           cout<<"Cost is "<<sd<<endl;
           }

       }

       }

       void findpaths(string source,int bud)
       {
           int s= getindex(source);
           dijkstra(s);

           cout<<"source vertex :"<<source<<endl;

           for(int v=0;v<=n;v++)
           {
             if(vertexlist[v].pathlength==infinity)
               {

               }
               else
                  findpath(s,v,bud);
           }
       }


    bool edgeexists(string s1, string s2)
    {
        return (isadjacent(getindex(s1),getindex(s2)));
    }

    void deleteedge(string s1, string s2)
    {
        int u=getindex(s1);
        int v= getindex(s2);
        if(isadjacent(u,v)==false)
            cout<<"edge not present"<<endl;
        else
        {
            adj[u][v]=-1;
            e--;
        }
    }

};
class persdetails  //class for collecting the personal details
{
    public:
   int trvlcode;
  int  age;
  string name;
  string add;
  int phnum;
  char sex;
  string passnum;
  string familyname;
  int num;
  int numppl;

  void p_input();
  void p_output();
  void givefam();
  int givecode();
  int give();
  int search1();
};
 void gotoxy(int x,int y)
 {
     cout<<setw(x);
     for(;y>0;y--)
        cout<<endl;
 }
int persdetails::give()
{
  return num;
}
void persdetails::givefam()
{
  cout<<familyname;
}
int persdetails::givecode()
{
  return trvlcode;
}
void persdetails::p_input()  //input func() of class1
{
  num=0;
  system("CLS");
  cout<<"\n\n\t:::::::::::::::::::::: PERSONAL DETAILS ::::::::::::::::::::::\n";
  cout<<"\t\t\t\t~~~~~~\n";
  cout<<"\n\t\t* Please fill in the details:\n\n\n\t\t\t1.Family Name: ";
  cin>>familyname;
  cout<<"\n\t\t\t2.Address: ";
  cin>>add;
  cout<<"\n\t\t\t3.Contact Number(10 Digit Mobile Number) : ";
  cin>>phnum;

}
void persdetails::p_output() //output func() of class1
{
system("CLS");
  cout<<"\n\n\t******* PERSONAL DETAILS *******"<<endl;
  cout<<"\n\n\t\t\tFamily Name:\t "<<familyname<<endl;
  cout<<"\t\t\tAddress:\t "<<add<<endl;
  cout<<"\t\t\tPhone Number:\t "<<phnum<<endl;
}

string query,name;

persdetails pd;
int found;

class travdetails   //class which holds the travel details
{
 public:
 string familyname;
  int day;
  int month;
  int year;
  int num1;
  int bdg_pt;
  int go_pt;
  string place;
  void source(int);
  long int budget();
  string boardingpoint();
  long int bud;
  void t_input();
  void t_output();
  void compute();
  void accept(int);
};
void travdetails:: source(int bdg)
{

    int c=bdg;
  switch(c)
  {
    case 1:cout<<"DELHI";
               place="DELHI";
	           break;
    case 2:cout<<"MUMBAI";
       place="MUMBAI";
	   break;
    case 3:cout<<"KOLKATA";
    place="KOLKATA";
	   break;
    case 4:cout<<"CHENNAI";
    place="CHENNAI";
	   break;
    case 5:cout<<"KERALA";
	   place="KERALA";
	   break;
    case 6:cout<<"JAIPUR";
    place="JAIPUR";
	   break;
    case 7:cout<<"OOTY";
    place="OOTY";
	   break;
    case 8:cout<<"AHMEDABAD";
    place="AHMEDABAD";
	   break;
    case 9:cout<<"CHANDIGARH";
    place="CHANDIGARH";
	   break;
   case 10:cout<<"NAINITAL";
   place="NAINITAL";
	   break;

  }

}
string travdetails::boardingpoint()
{
    return place;
}
long int travdetails::budget()
{
    return bud;
}
void travdetails::t_input() //input func()-class2
{
  int i=1,opt;
  while(i==1)
  {
  system("CLS");
    cout<<endl;
    cout<<"\n\n\t\t\t\t_||_TRAVEL DETAILS_";
    cout<<"\n\t\t\t\t\\_______/";
    cout<<"\n\t\t\t\t~~~~~~~~";
    cout<<"\n\n\t\tPlease enter the following details for your journey:";
    cout<<"\n\n\t\t*Note:Options marked with '*' are compulsory.\n\t\t\tPlease do select them.";
    cout<<"\n\n\n\t\t\t\t*1.Boarding Point\n\t\t\t\t*2.Date of Depature\n\t\t\t\t*3.budget\n\t\t\t\t*4.Back to main menu\n\n\t\t\t\t";
    cout<<"Enter your choice  ";
    cin>>opt;
    switch(opt)
    {
      case 1:system("CLS");
         cout<<endl;
         cout<<endl;
         cout<<"\n\n\t\t\t*** Select boarding point ***\n\n\n";
         cout<<endl;
	     cout<<"\t\t\t 1.DELHI\t\t\t    6.KERALA\t\t";
	     cout<<"\n\t\t\t 2.MUMBAI\t\t\t    7.JAIPUR\t\t";
	     cout<<"\n\t\t\t 3.AHMEDABAD\t\t\t    8.OOTY\t\t  ";
	     cout<<"\n\t\t\t 4.KOLKATA\t\t\t    9.CHANDIGARH\t\t";
	     cout<<"\n\t\t\t 5.CHENNAI\t\t\t    10.NAINITAL\t\t\n";
	     cin>>bdg_pt;
	     source(bdg_pt);

	     break;
      case 2:system("CLS");
	     cout<<"\n\n\tDate of Departure";
	     cout<<"\n\n   * Note:Format for entering:Day(press space)Month(press space)Year *";
	     cout<<"\n\n\t\tEnter your preferred date of departure: ";
	     cin>>day>>month>>year;
	     break;

	   case 3: cout<<"\t\t\tEnter budget =";
	             cin>>bud;
	             break;
       case 4:i=0;
	     break;
     default: break;
    }
  }

}
void boardpt(int c)  //for easy o/p
{
system("CLS");
switch(c)
  {
    case 1:cout<<"DELHI";
	   break;
    case 2:cout<<"MUMBAI";
	   break;
    case 3:cout<<"KOLKATA";
	   break;
    case 4:cout<<"CHENNAI";
	   break;
    case 5:cout<<"KERALA";
	   break;
    case 6:cout<<"JAIPUR";
	   break;
    case 7:cout<<"OOTY";
	   break;
    case 8:cout<<"AHMEDABAD";
	   break;
    case 9:cout<<"CHANDIGARH";
	   break;
   case 10:cout<<"NAINITAL";
	   break;

  }
}



void dest(int d)
{
  switch(d)
  {
    case 1:cout<<"DELHI";
	   break;
    case 2:cout<<"MUMBAI";
	   break;
    case 3:cout<<"KOLKATA";
	   break;
    case 4:cout<<"CHENNAI";
	   break;
    case 5:cout<<"KERALA";
	   break;
    case 6:cout<<"JAIPUR";
	   break;
    case 7:cout<<"OOTY";
	   break;
    case 8:cout<<"AHMEDABAD";
	   break;
    case 9:cout<<"CHANDIGARH";
	   break;
   case 10:cout<<"NAINITAL";
	   break;
  }
}
void travdetails::t_output()  //output func()-class2
{
  system("CLS");
  cout<<endl;
  cout<<endl;
  cout<<endl;
  cout<<endl;
  cout<<endl;
  cout<<"\n\n\t\t\t\t****** TRAVEL DETAILS ********";
  cout<<"\n\n\t\t\t\t\t\tBoarding Point: ";
  cout<<place;

  cout<<"\n\n\t\t\t\t\t\tDate of departure: "<<day<<"/"<<month<<"/"<<year;
  cout<<endl;
  cout<<endl;
  cout<<"\t\t\t\t\t\tbudget is "<<bud<<endl;
}

travdetails td;

int main()
{
int m,n,l,p;
char z;
int ch;
z='y';

system("cls");
string source;
    directedgraph g;
    g.insertvertex("DELHI");
    g.insertvertex("MUMBAI");
    g.insertvertex("AHMEDABAD");
    g.insertvertex("KOLKATA");
    g.insertvertex("CHENNAI");
    g.insertvertex("KERALA");
    g.insertvertex("JAIPUR");
    g.insertvertex("OOTY");
    g.insertvertex("CHANDIGARH");
    g.insertvertex("NAINITAL");


    g.insertedge("DELHI","MUMBAI",49000);
    g.insertedge("MUMBAI","AHMEDABAD",37000);
    g.insertedge("AHMEDABAD","KOLKATA",53000);
    g.insertedge("KOLKATA","CHENNAI",78000);
    g.insertedge("CHENNAI","KERALA",60000);
    g.insertedge("KERALA","JAIPUR",90000);
    g.insertedge("JAIPUR","OOTY",54000);
    g.insertedge("OOTY","CHANDIGARH",90000);
    g.insertedge("CHANDIGARH","NAINITAL",27000);
    g.insertedge("OOTY","CHENNAI",19000);
    g.insertedge("CHENNAI","NAINITAL",80000);
    g.insertedge("NAINITAL","DELHI",89000);
    g.insertedge("DELHI","KERALA",46000);
    g.insertedge("KERALA","OOTY",77000);
    g.insertedge("NAINITAL","MUMBAI",78000);
    g.insertedge("MUMBAI","KERALA",70000);
    g.insertedge("OOTY","JAIPUR",89000);
    g.insertedge("JAIPUR","AHMEDABAD",51000);


   int bud;


while(z=='y')
{
system("CLS");
fflush(stdin);
cout<<"*****menu*****";
cout<<"\n1)CUSTOMER DETAILS\n2)TRAVEL DETAILS\n3)TOUR PACKAGE";
cout<<endl;
cout<<"Enter your choice=";
cin>>m;
if(m==1)
{
cout<<"*****customer menu******";
cout<<"\n1. Add a new Customer\n2. List all Customer\n3. Exit\n=================\n";
cout<<"Enter the choice:";
cin>>ch;

switch(ch)
{
case 3:
cout<<"\n\tAre you sure u want to exit?";
break;

case 1:
         system("cls");
         pd.p_input();
         system("CLS");
         break;


case 2: system("cls");
        pd.p_output();
        break;

default: break;
}
}
else if(m==2)
{
    system("CLS");
    cout<<"*******travel menu*********";
    cout<<"\n1)enter details of trip";
    cout<<"\n2)display details of trips";
    cout<<endl;
    int f;
    cout<<"Enter your choice =";
    cin>>f;
    switch(f)
    {
     case 1:   system("CLS");
               td.t_input();

               break;
     case 2:system("cls");

              td.t_output();
              break;
     default : break;

    }
}
else if(m==3)
{
      system("CLS");
      cout<<"YOUR TOUR PACKAGE IS"<<endl;
     source= td.boardingpoint();
     bud=td.budget();

   g.findpaths(source,bud);
}
else
     cout<<"wrong choice"<<endl;
cout<<"\t\t\tdo want to continue"<<endl;
cin>>z;
}

return 0;
}
