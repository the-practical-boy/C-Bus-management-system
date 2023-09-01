#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;

class Bus
{
    string t_no;
    public:
    string b_no,b_name,d_name;
    long int b_seats,d_no;
    void menu();
    void new_bus();
    void bus_view();
    void single_bus_view();
    void all_bus_view();
    void update_bus();
    void del_bus();
    void bus_route();
    void bus_details();
    void booking();
    void renew_bus();
};
void Bus:: menu()
{
    int choice;
    xl:
    system("cls");
    cout<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"\n\n\n\t\t\t________Bus Management System________";
    cout<<"\n\n\n\t 1. ADD BUS RECORD";
    cout<<"\n\t 2. VIEW BUS DETAILS";
    cout<<"\n\t 3. UPDATE BUS DETAIL";
    cout<<"\n\t 4. DELETE BUS DETAIL";
    cout<<"\n\t 5. BUS ROUTE";
    cout<<"\n\t 6. BUS BOOKING DETAILS";
    cout<<"\n\t 7. BOOK YOUR SEAT";
    cout<<"\n\t 8. RENEW THE SEATS";
    cout<<"\n\t 9. EXIT";
    cout<<"\n\n-->Choose your option number: ";
    cin>>choice;
    switch(choice)
    {
        case 1: new_bus();
            break;
        case 2: bus_view();
            break;
        case 3: update_bus();
            break;
        case 4: del_bus();
            break;
        case 5: bus_route();
            break;
        case 6: bus_details();
            break;
        case 7: booking();
            break;
        case 8: renew_bus();
            break;
        case 9: 
        system("cls");
        cout<<"\n\n\n\n\n\n\t\t\t\tExiting the System.........";
        cout<<"\nWelcome Back";
        Sleep(2000);
        exit(0);
            break;
        default:
            cout<<"\n\nIncorrect option selected! Please try again";
            Sleep(2000);
            system("cls");
            goto xl;
    }

}
void Bus:: new_bus()
{
    p:
    system("cls");
    fstream file;
    ofstream file2;
    int found=0;
   long int tb_seats,td_no; string tb_no,tb_name,td_name;
    cout<<"\n\n\n\t\t\t________ADD BUS RECORD________";
    cout<<"\n\nEnter Bus Number: ";
    cin>>b_no;
    cout<<"\n\nEnter bus company name in capital letters: ";
    cin>>b_name;
    cout<<"\n\nEnter Bus seats: ";
    cin>>b_seats;
    cout<<"\n\nEnter Bus Driver name: ";
    fflush(stdin);
    getline(cin,d_name);
    cout<<"\n\nEnter driver phone no.: ";
    cin>>d_no;
    file.open("bus.txt",ios::in);

    if(!file)
    {
        file.open("bus.txt",ios::app|ios::out);
        file<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\t     "<<d_no<<"\n";
        file.close();
    }
    else
    {
        while (file.eof()==0)
        {
        file>>tb_no>>tb_name>>tb_seats>>td_name>>td_no;
            if(b_no==tb_no)
            {
                found++;
            }
            
        }
        if(found==0)
        {
            file2.open("bus.txt",std::ios_base::app);
            file2<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\t     "<<d_no<<"\n";
            file.close();
            file2.close();
        }
        else
        {
            cout<<"\n\n\n\t\t\tFile already exists....";
            cout<<"\n\n\nPress any button to Re-Enter Bus record";
            goto p;
        }
    }
    cout<<"\n\n\n_________Data Successfully Added________";
    cout<<"\nPress any button to go back to Main Menu...";
    getch();
    menu();

}

void Bus:: bus_view()
{
    p1:
    system("cls");
    int choice;
    cout<<"\n\n\n\t\t\t________Bus Management System________"<<endl;
    cout<<"\n[1] View Specific Bus Detail";
    cout<<"\n[2] View All Bus Details";
    cout<<"\n[3] Return To Main Menu";
    cout<<"\n\nEnter Your Choice Number: ";
    cin>>choice;
    switch(choice)
    {
        case 1: single_bus_view();
            break;
        case 2: all_bus_view();
            break;
        case 3:menu();
            break;
        default:
        cout<<"\n\n\tYou Entered Invalid Input\n\tPlease Try Again....";
    }
    
     getch();
        goto p1;

}
void Bus::single_bus_view()
{
    x:
    system("cls");
    cout<<"\n\n\n\t\t\t________Bus Management System________"<<endl;
    
    ifstream file;
    int found =0;
    string t_no;
    file.open("bus.txt",ios::in);
    if(!file)
    {
        int c;
        cout<<"\n File doesn't exist...";
        
        cout<<"\n\nPress 1 for Re-Enter \nPress 2 to go back to main menu";
        cin>>c;
        if(c==1)
        {
            goto x;

        }
        else{
            menu();
        }
    }
    else
    {
        cout<<"\n\tEnter Bus Number: ";
        cin>>t_no;
        file>>b_no>>b_name>>b_seats>>d_name>>d_no;
        while(!file.eof())
        {
            if(t_no==b_no)
            {
                cout<<"\nBUS NO\tBUS COMPANY NAME \tBUS SEATS\tDRIVER NAME \tDRIVER Phone No.";
                cout<<endl<<b_no<<"\t\t"<<b_name<<"\t\t"<<b_seats<<"\t\t"<<d_name<<"\t\t   "<<d_no;
                found++;

            }
            file>>b_no>>b_name>>b_seats>>d_name>>d_no;
            

        }
        file.close();
        if(found==0)
        {
            cout<<"BUS Number not found..."<<endl;
            getch();
            menu();
        }

    }

}
void Bus::all_bus_view()
{
    x2:
    system("cls");
    cout<<"\n\n\n\t\t\t________Bus Management System________"<<endl;
    
    ifstream file;

    
    file.open("bus.txt",ios::in);
    if(!file)
    {
        int c;
        cout<<"\n File doesn't exist...";
        
        cout<<"\n\nPress 1 for Re-Enter \nPress 2 to go back to main menu";
        cin>>c;
        if(c==1)
        {
            goto x2;

        }
        else
        {
            menu();
        }
    }
    else
    {
       cout<<"\nBUS NO\t  BUS COMPANY NAME\tBUS SEATS\t DRIVER NAME\t   DRIVER Phone No.";
      
        
            file>>b_no>>b_name>>b_seats>>d_name>>d_no;
        while(!file.eof())
        {
            
                
                cout<<endl<<"  "<<b_no<<"\t\t"<<b_name<<"\t\t   "<<b_seats<<"\t\t  "<<d_name<<"\t\t   "<<d_no<<endl;
                
 
            file>>b_no>>b_name>>b_seats>>d_name>>d_no;

        }
        
     file.close();
    }

}
void Bus::update_bus()
{
    
    system("cls");
    fstream file; ofstream file2;
    int found=0;
    string no,tb_name,td_name;long int tb_seats,td_no;

    cout<<"\n\n\n\t\t\t________Bus Management System________"<<endl;
    file.open("bus.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nFile doesn't exist...";
    }
    else
    {
        cout<<"\nEnter Bus number you want to update: ";
        cin>>t_no;
        file2.open("bus1.txt",ios::app|ios::out);
        file>>b_no>>b_name>>b_seats>>d_name>>d_no; 
        while(!file.eof())
        {
            

            if(b_no==t_no)
            {
                // cout<<"Yes";
                cout<<"\nEnter new Bus number: ";
                cin>>no;
                cout<<"\nEnter new Bus name: ";
                cin>>tb_name;
                cout<<"\nEnter new Bus seats: ";
                cin>>tb_seats;
                cout<<"\nEnter new Driver name: ";
                fflush(stdin);
                getline(cin,td_name);
                cout<<"\nEnter new Driver number: ";
                cin>>td_no;
                found++;
                file2<<no<<" "<<tb_name<<" "<<tb_seats<<" "<<td_name<<" "<<td_no<<endl;
                cout<<endl<<"  "<<no<<"\t\t"<<tb_name<<"\t\t   "<<tb_seats<<"\t\t  "<<td_name<<"\t\t   "<<td_no<<endl;
            }
            else
            {
                file2<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<" "<<d_no<<endl;
                cout<<endl<<"  "<<b_no<<"\t\t"<<b_name<<"\t\t   "<<b_seats<<"\t\t  "<<d_name<<"\t\t   "<<d_no<<endl;
            }
            file>>b_no>>b_name>>b_seats>>d_name>>d_no;
            
        }
        if(found==0)
            {
                cout<<"\n\nBus number is incorrect to update....";
                file2.close();
                remove("bus1.txt");
                file.close();

            }
            else
            {
                file.close();
                file2.close();
                remove("bus.txt");
                rename("bus1.txt","bus.txt");
                cout<<"\n\nBus record updated successfully....";
            }
    }
    cout<<"\nPress any key to go to Main Menu...";
    getch();
    menu();

}
void Bus::del_bus()
{
    
    system("cls");
    fstream file; ofstream file2;
    int found=0;
    string no,tb_name,td_name;long int tb_seats,td_no;

    cout<<"\n\n\n\t\t\t________Bus Management System________"<<endl;
    file.open("bus.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nFile doesn't exist...";
    }
    else
    {
        cout<<"\nEnter Bus number you want to delete: ";
        cin>>t_no;
        file2.open("bus1.txt",ios::app|ios::out);
        file>>b_no>>b_name>>b_seats>>d_name>>d_no; 
        while(!file.eof())
        {
            

            if(b_no==t_no)
            {
                
                found++;
                
                cout<<endl<<"  "<<no<<"\t\t"<<tb_name<<"\t\t   "<<tb_seats<<"\t\t  "<<td_name<<"\t\t   "<<td_no<<endl;
            }
            else
            {
                file2<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<" "<<d_no<<endl;
                cout<<endl<<"  "<<b_no<<"\t\t"<<b_name<<"\t\t   "<<b_seats<<"\t\t  "<<d_name<<"\t\t   "<<d_no<<endl;
            }
            file>>b_no>>b_name>>b_seats>>d_name>>d_no;
            
        }
        if(found==0)
            {
                cout<<"\n\nBus number is incorrect to update....";
                file2.close();
                remove("bus1.txt");
                file.close();

            }
            else
            {
                file.close();
                file2.close();
                remove("bus.txt");
                rename("bus1.txt","bus.txt");
                cout<<"\n\nBus record deleted Successfully.....";
            }
    }
    cout<<"\nPress any key to go to Main Menu...";
    getch();
    menu();

}
void Bus::bus_route()
{
    int choice;
    system("cls");
    cout<<"\n\n\n\t\t\t________Bus Management System________"<<endl;
    cout<<"\n[1] FZR to CHD route details: ";
    cout<<"\n[2] CHD to Amritsar route details: ";
    cout<<"\n[3] CHD to Shimla route details: ";
    cout<<"\n[4] CHD to Delhi route details: ";
    cout<<"\n[5] CHD to Dehradun route details: ";
    cout<<"\n\nPlease enter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            cout<<"\n       Ferozepur                  ";
            cout<<"\n4:45AM.....................6:00AM";
            cout<<"\n      Talwandi Bhai               ";
            cout<<"\n6:02AM.....................6:30AM";
            cout<<"\n          Moga                    ";
            cout<<"\n6:32AM.....................7:05AM";
            cout<<"\n         Jagraon                  ";
            cout<<"\n7:07AM.....................7:40AM";
            cout<<"\n         Ludhiana                 ";
            cout<<"\n8:00AM.....................9:15AM";
            cout<<"\n         Samrala                  ";
            cout<<"\n9:16AM.....................9:50AM";
            cout<<"\n         Chandigarh               ";
            break;
        case 2:
            cout<<"\n          Chandigarh                ";
            cout<<"\n10:00AM.....................10:30AM";
            cout<<"\n          Kharar                    ";
            cout<<"\n10:35AM.....................11:15AM";
            cout<<"\n          Samrala                ";
            cout<<"\n11:20AM.....................11:50PM";
            cout<<"\n          Kohara                ";
            cout<<"\n11:55.....................12:10PM";
            cout<<"\n          Sahnewal                ";
            cout<<"\n12:15PM.....................12:40PM";
            cout<<"\n          Ludhiana                ";
            break;
        case 3:
            cout<<"\n          Chandigarh                ";
            cout<<"\n02:00PM.....................02:30PM";
            cout<<"\n          Banur                ";
            cout<<"\n02:32PM.....................03:00PM";
            cout<<"\n          Rajpura                ";
            cout<<"\n03:05PM.....................03:30PM";
            cout<<"\n          Bir Bahadurgarh                ";
            cout<<"\n03:32PM.....................03:50PM";
            cout<<"\n          Patiala                ";
            break;
        case 4:
            cout<<"\n          Chandigarh                ";
            cout<<"\n12:00AM.....................12:30AM";
            cout<<"\n          Panchkula                ";
            cout<<"\n12:35AM.....................01:30AM";
            cout<<"\n          Pinjore                ";
            cout<<"\n01:32AM.....................01:50AM";
            cout<<"\n          Kalka                ";
            cout<<"\n01:52AM.....................03:00AM";
            cout<<"\n          Dharampur                ";
            cout<<"\n03:02AM.....................03:50AM";
            cout<<"\n          Solan                ";
            cout<<"\n03:52AM.....................05:30AM";
            cout<<"\n          Shimla                ";
            break;
        case 5:
            cout<<"\n          Chandigarh                ";
            cout<<"\n12:00PM.....................12:30PM";
            cout<<"\n          Chandigarh                ";
            cout<<"\n12:30AM.....................12:30AM";
            break;
        default:
            break;
    }
    cout<<"\nPress any key to go to Main Menu...";
    getch();
    menu();
    
}



void Bus::bus_details()
{
    system("cls");
    cout<<"\n\n\n\t\t\t________Bus Management System________"<<endl;
    fstream file,file1;
    string no,s_no,s_b_no;
    int count =0,found=0;
    file.open("bus.txt",ios::in);
    file1.open("seats.txt",ios::in);
    if(!file||!file1)
    {
        cout<<"\n\n\nFile couldn't be found...";
    }
    else
    {
        cout<<"\nEnter Bus number: ";
        cin>>no;
        file1>>s_b_no>>s_no;
        while(!file1.eof())
        {
            if(no==s_b_no)
            {
                count++;
            }
            file1>>s_b_no>>s_no;
        }
        file1.close();
        file>>b_no>>b_name>>b_seats>>d_name>>d_no;
        while(!file.eof())
        {
            if(no==b_no)
            {
                system("cls");
                cout<<"\nTotal number of seats: "<<b_seats;
                cout<<"\nTotal number of reserved seats: "<<count;
                cout<<"\nTotal number of seats Unreserved: "<<b_seats-count;
                found++;
            }
            file>>b_no>>b_name>>b_seats>>d_name>>d_no;
        }
        if(found==0)
        {
            cout<<"\ninvalid Bus number...";
        }
        file.close();
    }
    cout<<"\nPress any key to go to Main Menu...";
    getch();
    menu();

}


void Bus::booking()
{
    p:
    system("cls");
    cout<<"\n\n\n\t\t\t________Bus Management System________"<<endl;
    string t_no,s_b_no;
    int found=0,s_no,seats,count=0,s_s_no,ss_no[25];
    int j=0;
    string customer_name,phone,from,to;
    int s_amount,total_amount=0,r_amount;
    char x;
    fstream file,file1;
    file.open("bus.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nFile couldn't ffind...";
    }
    else
    {
        cout<<"\nBus number: ";
        file1.open("seats.txt",ios::in);
       if(file1)
       { 
        file1>>s_b_no>>s_s_no; 

        while (!file1.eof())
        {
            if(t_no==s_b_no)
            {
                count++;
            }
            file1>>s_b_no>>s_s_no; 

        }
        file1.close();

       }

        cin>>t_no;
        file>>b_no>>b_name>>b_seats>>d_name>>d_no;
        while(!file.eof())
        {
            if(t_no==b_no)
            {
                seats=b_seats;
                found++;
            }
            file>>b_no>>b_name>>b_seats>>d_name>>d_no;
        }

        file.close();
        if(count==0)
        {
             cout<<"\n\nInvalid Bus number...";
        }
     
        else if(seats==count)
        {
            cout<<"\n\nAll seats are already reserved...";
        }

        else if(found==1)
        {
            do
            {
                i:
                cout<<"\nEnter Seat number: ";
                cin>>s_no;
                if(s_no>seats)
                {
                    cout<<"\nInvalid bus seat number; Please try again...";
                    goto i;
                }

                file1.open("seats.txt",ios::in);
                if(!file1)
                {
                    file1.open("seats.txt",ios::app|ios::out);
                    file1<<t_no<<" "<<s_no<<"\n";        
                    file1.close();
                }
                else
                {
                    file1>>s_b_no>>s_s_no; 
                    while(!file1.eof())
                    {
                        if(t_no==s_b_no && s_no==s_s_no)
                        {
                            cout<<"\n Seat already reserved...Please try again...";
                            file1.close();
                            goto i;
                        }
                        file1>>s_b_no>>s_s_no; 
                    }
                    ss_no[j]=s_no;
                    cout<<ss_no[j];
                    j++;
                    cout<<j<<endl;

                    file1.close();
                    file1.open("seats.txt",ios::app|ios::out);
                    file1<<t_no<<" "<<s_no<<"\n";
                    file1.close();

                }
                

                cout<<"\nYou want to book another, Please Choose option [Y,N] ";
                cin>>x;

            } while (x=='y'||x=='Y');
            system("cls");
            cout<<j<<endl;
            cout<<"\n\n\n\t\t\t________Bus Management System________"<<endl;
            cout<<"\n\nCustomer Name: ";
            fflush(stdin);
            getline(cin,customer_name);
            cout<<"\nPhone Number: ";
            cin>>phone;
            cout<<"\n\nFrom: ";
            cin>>from;                        
            cout<<"\nTo: ";
            cin>>to;
            cout<<"\nEnter Amount of single bus = ";
            cin>>s_amount;
            total_amount=s_amount*j;
            cout<<"\n\nTotal amount = "<<total_amount;
            cout<<"\nReceived amount = ";
            cin>>r_amount;
            
            file1.open("customer.txt",ios::app|ios::in);
            file1<<customer_name<<" "<<j<<" "<<phone<<" "<<t_no<<" "<<total_amount<<"\n";
            file1.close();

            system("cls");
            cout<<"\n\n\n\t\t_________Bus Management System_________"<<endl;
            cout<<"\n\t\t****************************************";
            cout<<"\n\n\t\t________Your Booking information________"<<endl;
            cout<<"\n\t\t****************************************";
            cout<<"\n\n\t\tName:            "<<customer_name;
            cout<<"\n\t\tFrom:            "<<from;
            cout<<"\n\t\tTo:              "<<to;
            cout<<"\n\t\tTotal seats:     "<<j;
            cout<<"\n\t\tReserved seats:  ";
            for(int x=0;x<j;x++)
            {
                cout<<ss_no[x];
                
                if(x!=j-1)
                cout<<",";
                else
                cout<<" | ";
            }
            cout<<"\n\t\tSingle Seat Amount:    "<<s_amount;
            cout<<"\n\t\tTotal  Amount:         "<<total_amount;
            cout<<"\n\t\tReceived Amount:       "<<r_amount;
            cout<<"\n\t\tAmount returned back = "<<r_amount-total_amount;
            cout<<"\n\n\t\t****************************************";
            cout<<"\n\t\t   We wish you a Happy and Safe JOurney ";
            cout<<"\n\t\t****************************************";
        }
        else
        {
            cout<<"\n\nInvalid Bus number entered.....";
            getch();
            goto p;
        }
    }

cout<<"\nPress any key to go to Main Menu...";
    getch();
    menu();
}

void Bus::renew_bus()
{
    char ch;
    fstream file,file1;
    system("cls");
    file.open("seats.txt",ios::in);
    file1.open("customer.txt",ios::in);
    cout<<"\n\n\n\t\t_________Bus Management System_________"<<endl;
    cout<<"\n\n\n\t\tWarning! Do you want to clear the files and renew the seats...Enter[Y,N]";
    cin>>ch;
    if(ch=='y'||ch=='Y')
    {
        file.close();
        file1.close();
        remove("seats.txt");
        remove("customer.txt");
        file1.open("customer.txt",ios::app|ios::out);
        file.open("seats.txt",ios::app|ios::out);
        file.close();
        file1.close();
        cout<<"\n\nAll Bookings cleared...";
    }
    else
    {
        cout<<"\n\nAction revoked...";
    }

cout<<"\nPress any key to go to Main Menu...";
    getch();
    menu();
}





int main(int argc, char const *argv[])
{
    Bus b;
    string email,pass;
    char ch;
    label:
    fflush(stdin);
    cout<<"\n\n\t\t\t*******Security Required********";
    cout<<"\n\n\nEnter email: ";
    cin>>email;

    cout<<"\nEnter Authority PassKey: ";
    for(int i=0;i<6;i++)
    {
        ch=getch();
        pass+=ch;
        cout<<"X ";
        
    }
    getch();
    if(email=="v"&&pass=="bussit")
    {
        Sleep(500);
        cout<<"\n\n\n\t\t\tLoading Please Wait";
        
        for(int i=0;i<5;i++)
        {
            Sleep(800);
            cout<<".";
        }
        system("cls");
        Sleep(2000);
        b.menu();
    }
    else 
    {
        Sleep(1000);
        cout<<"\n\n\n\t\t\tWARNING!!! You entered incorrect PassKey, please try again...";
        Sleep(2000);
        system("cls");
        goto label;
    }
    return 0;
}