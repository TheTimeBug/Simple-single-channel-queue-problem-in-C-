#include<bits/stdc++.h>
using namespace std;

    int consumer;
    int interArrivalTime[99];    //data for inter arrival time
    int serviceTime[99];         //Consumer Service time
    int arrivalTime[99];         //Arrival time on clock
    int begainTime[99];         //store begin time
    int endTime[99];            //store end time


    void input(int n);  //will used to take input form user.
    void process(int n); // execute the process
    void print(int n);  //print the answer

int main(){

    cout<< "Enter Number of Consumer : "; cin>> consumer;
    cout<< "Enter Starting Time : " ; cin >> arrivalTime[0];
    input(consumer);

    cout<< "\n\n\nCalculateing. . . . . . . . . . \n\n\n" <<endl;

    process(consumer);

    print(consumer);


}

void input(int n){

    for(int i=0;i<n;i++){
        cout<< "Enter inter arrival time for consumer " << i+1 <<" : " ;
        cin>> interArrivalTime[i];
        cout<< "Enter Servicetime for consumer        " << i+1 <<" : " ;
        cin>> serviceTime[i];
    }
    //calculateing Arrival time accoding to interarrival time .
    for(int i=1;i<n;i++){
         arrivalTime[i]=arrivalTime[i-1]+interArrivalTime[i];
    }
}

 void process(int n){

    //calculateing begain time and end time.
    for(int i=0;i<n;i++){
        if(endTime[i-1]>=arrivalTime[i]&& i!=0){
            begainTime[i] = endTime[i-1];
            endTime[i]=begainTime[i]+serviceTime[i];
        }
        else{
            begainTime[i] = arrivalTime[i];
            endTime[i]=begainTime[i]+serviceTime[i];
        }
    }
 }

 void print(int n){

    cout<< "Simulation Table Emphasizing Clock Times:    \n";
   cout<< "--------------------------------------------------------------------------------"<< endl;
   cout<< "|  consumer   |   Arrival Time  | Service Begin | Service Time |  Service End  |" << endl;

    for(int i=0;i<n;i++){
        printf("| %7d  %14d  %14d  %14d  %14d      |\n", i+1, arrivalTime[i],begainTime[i],serviceTime[i],endTime[i]);
    }
     cout<< "--------------------------------------------------------------------------------\n\n"<< endl;
 }
