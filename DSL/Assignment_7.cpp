// NAME : HARSHAL PATIL
// ROLL NO : 44

// Assignment 7 : Appointment Management

#include <iostream>
using namespace std;

int size; // No of Nodes or Appointments

struct SLL_Node // Node Structure of each Appointment
{
    int startTime;
    int endTime;
    int minTime;
    int maxTime;
    int flag;
    struct SLL_Node *next;
} *head;

class App_Shedule
{
public:
    void createSchedule();

    void displaySchedule();

    void bookAppointment();

    void cancleAppointment();

    void sortingAppointment();

} A1;

int main()
{
    int ch;
    char ans;

    do
    {
        cout << "\n\n --- Menu ---";
        cout << "\n 1. Create Appointment Schedule";
        cout << "\n 2. Display Free Slots";
        cout << "\n 3. Book an Appointment";
        cout << "\n 4. Cancel an Appointment";
        cout << "\n 5. Sort slots based on Time";

        cout << "\n\n Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            A1.createSchedule();
            break;

        case 2:
            A1.displaySchedule();
            break;

        case 3:
            A1.bookAppointment();
            break;

        case 4:
            A1.cancleAppointment();
            break;

        case 5:
            A1.sortingAppointment();
            break;

        default:
            cout << "\n\t Wrong choice!!!";
        }

        cout << "\n\n Do you wanna continue? (y/n) : ";
        cin >> ans;
    } while (ans == 'y');
}

void App_Shedule ::createSchedule() // Function Definition to create Appointment Schedule
{
    int i;
    struct SLL_Node *temp, *last;

    head = NULL;

    cout << "\n\n\t How many Appointment Slots: ";
    cin >> size;

    for (i = 0; i < size; i++)
    {
        temp = new (struct SLL_Node); // Step 1: Dynamic Memory Allocation

        cout << "\n\n\t Enter startTime Time: "; // Step 2: Assign Data & Address
        cin >> temp->startTime;
        cout << "\n\t Enter endTime Time: ";
        cin >> temp->endTime;
        cout << "\n\n\t Enter minTime Duration: ";
        cin >> temp->minTime;
        cout << "\n\t Enter maxTime Duration: ";
        cin >> temp->maxTime;
        temp->flag = 0;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            last = head;
        }
        else
        {
            last->next = temp;
            last = last->next;
        }
    }
}

void App_Shedule ::displaySchedule() // Function Definition to Display Appointment Schedule
{
    int cnt = 1;
    struct SLL_Node *temp;

    cout << "\n\n\t ---*Appointment Schdule---*";
    cout << "\n\n\t Srno.\tstartTime\tendTime\tminTime_Dur\tmaxTime_Dur\tStatus";

    temp = head;
    while (temp != NULL)
    {
        cout << "\n\n\t " << cnt;
        cout << "\t " << temp->startTime;
        cout << "\t " << temp->endTime;
        cout << "\t  " << temp->minTime;
        cout << "\t  " << temp->maxTime;

        if (temp->flag)
            cout << "\t-Booked-";
        else
            cout << "\t--Free--";

        temp = temp->next;
        cnt++;
    }
}

void App_Shedule ::bookAppointment() // Function Definition to Book Appointment
{
    int startTime;
    struct SLL_Node *temp;

    cout << "\n\n\t Please enter Appointment time: ";
    cin >> startTime;

    temp = head;

    while (temp != NULL)
    {
        if (startTime == temp->startTime)
        {
            if (temp->flag == 0)
            {
                cout << "\n\n\t Appointment Slot is Booked!!!";
                temp->flag = 1;
            }
            else
                cout << "\n\n\t Appointment Slot is not Available!!!";
        }

        temp = temp->next;
    }
}

void App_Shedule ::cancleAppointment() // Function Defination to Cancel Appointment
{
    int startTime;
    struct SLL_Node *temp;

    cout << "\n\n\t Please enter Appointment time to Cancel: ";
    cin >> startTime;

    temp = head;

    while (temp != NULL)
    {
        if (startTime == temp->startTime)
        {
            if (temp->flag == 1)
            {
                cout << "\n\n\t Your Appointment Slot is Canceled!!!";
                temp->flag = 0;
            }
            else
                cout << "\n\n\t Your Appointment was not Booked!!!";
        }

        temp = temp->next;
    }
}

void App_Shedule ::sortingAppointment() // Function Definition to Sort Appointments
{
    int i, j, val;
    struct SLL_Node *temp;

    for (i = 0; i < size - 1; i++)
    {
        temp = head;
        while (temp->next != NULL)
        {
            if (temp->startTime > temp->next->startTime)
            {
                val = temp->startTime;
                temp->startTime = temp->next->startTime;
                temp->next->startTime = val;

                val = temp->endTime;
                temp->endTime = temp->next->endTime;
                temp->next->endTime = val;

                val = temp->minTime;
                temp->minTime = temp->next->minTime;
                temp->next->minTime = val;

                val = temp->maxTime;
                temp->maxTime = temp->next->maxTime;
                temp->next->maxTime = val;
            }
            temp = temp->next;
        }
    }

    cout << "\n\n\t The Appointments got Sorted!!!";
}