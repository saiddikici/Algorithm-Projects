/* MUHAMMED SAID DIKICI 150140007
ANALYSIS OF ALGORITHMS PROJECT 2
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cstring>
using namespace std;
/*
    employee struct
*/
struct employee{
    int ID, number_of_calls, positive_feedback, negative_feedback, performance_score;
    employee(){
        ID=0;
    }
};

/*
    swap function
*/

void swaps(employee &a,employee &b){
    employee tmp = a;
    a = b;
    b = tmp;
}

/*
    left child function
*/

int leftchild(int i){
    int b;
    return b = 2 * i + 1;
}

/*
    right child function
*/

int rightchild(int i){
    int b;
    return b = 2 * i + 2;
}
/*
    parent function
*/
int parent(int i){
    int b;
    return b = (i-1)/2;
}

/*
    max heapify for number of calls
*/
void max_heapify_calls(employee incomingarray[], int i, int heapsize){
    int l = leftchild(i);
    int r = rightchild(i);
    int largest = i;
    if(l<heapsize && incomingarray[l].number_of_calls > incomingarray[i].number_of_calls){
        largest = l;
    }
    else{
        largest = i;
    }
    if(r<heapsize && incomingarray[r].number_of_calls > incomingarray[largest].number_of_calls){
        largest = r;
    }
    if(largest != i){
        swaps(incomingarray[i], incomingarray[largest]);
        max_heapify_calls(incomingarray, largest, heapsize);
    }
}

/*
    max heapify for performance score
*/

void max_heapify_performance(employee incomingarray[], int i, int heapsize){
    int l = leftchild(i);
    int r = rightchild(i);
    int largest = i;

    if(l<heapsize && incomingarray[l].performance_score > incomingarray[i].performance_score){
        largest = l;
    }

    if(r<heapsize && incomingarray[r].performance_score > incomingarray[largest].performance_score){
        largest = r;
    }

    if(largest != i){
        swaps(incomingarray[i], incomingarray[largest]);
        max_heapify_performance(incomingarray, largest, heapsize);
    }

}

/*
    min heapify for number of calls
*/

void min_heapify_calls(employee incomingarray[], int i, int heapsize){
    int l = leftchild(i);
    int r = rightchild(i);
    int smallest = i;
    if(l<heapsize && incomingarray[l].number_of_calls < incomingarray[i].number_of_calls){
        smallest = l;
    }
    if(r<heapsize && incomingarray[r].number_of_calls < incomingarray[smallest].number_of_calls){
        smallest = r;
    }
    if(smallest != i){
        swaps(incomingarray[i], incomingarray[smallest]);
        min_heapify_calls(incomingarray, smallest, heapsize);
    }
}

/*
    min heapify for performance score
*/


void min_heapify_performance(employee incomingarray[], int i, int heapsize){
    int l = leftchild(i);
    int r = rightchild(i);
    int smallest = i;

    if(l<heapsize && incomingarray[l].performance_score < incomingarray[i].performance_score){
        smallest = l;
    }

    if(r<heapsize && incomingarray[r].performance_score < incomingarray[smallest].performance_score){
        smallest = r;
    }

    if(smallest != i){
        swaps(incomingarray[i], incomingarray[smallest]);
        min_heapify_performance(incomingarray, smallest, heapsize);
    }
}


/*
    builds number of calls max heap
*/


void build_max_heap_calls(employee incomingarray[], int heapsize){
    for(int i=heapsize/2-1; i>=0;i--){
        max_heapify_calls(incomingarray, i, heapsize);
    }
}

/*
    builds performance score max heap
*/

void build_max_heap_performance(employee incomingarray[], int heapsize){
    for(int i=heapsize/2-1; i>=0;i--){
        max_heapify_performance(incomingarray, i, heapsize);
    }
}

/*
    builds number of calls min heap
*/


void build_min_heap_calls(employee incomingarray[], int heapsize){
    for(int i=heapsize/2-1; i>=0;i--){
        min_heapify_calls(incomingarray, i, heapsize);
    }
}

/*
    builds performance score min heap
*/

void build_min_heap_performance(employee incomingarray[], int heapsize){
    for(int i=heapsize/2-1; i>=0;i--){
        min_heapify_performance(incomingarray, i, heapsize);
    }
}

/*
    heapsort for number of calls increasing order
*/

void heapsort_max_calls(employee incomingarray[], int heapsize){
    build_max_heap_calls(incomingarray, heapsize);
    for(int i=heapsize-1;i>0;i--){
        swaps(incomingarray[0], incomingarray[i]);
        max_heapify_calls(incomingarray, 0, i);
    }
}

/*
    heapsort for performance score increasing order
*/

void heapsort_max_performance(employee incomingarray[], int heapsize){
    build_max_heap_performance(incomingarray, heapsize);
    for(int i=heapsize-1;i>0;i--){
        swaps(incomingarray[0], incomingarray[i]);
        max_heapify_performance(incomingarray, 0, i);
    }
}

/*
    heapsort for number of calls decreasing order
*/

void heapsort_min_calls(employee incomingarray[], int heapsize){
    build_min_heap_calls(incomingarray, heapsize);
    for(int i=heapsize-1;i>0;i--){
        swaps(incomingarray[0], incomingarray[i]);
        min_heapify_calls(incomingarray, 0, i);
    }
}

/*
    heapsort for performance score increasing order
*/

void heapsort_min_performance(employee incomingarray[], int heapsize){
    build_min_heap_performance(incomingarray, heapsize);
    for(int i=heapsize-1;i>0;i--){
        swaps(incomingarray[0], incomingarray[i]);
        min_heapify_performance(incomingarray, 0, i);
    }
}


int arraysize_max_calls = 0;//holds size of number of calls' max heap
int arraysize_min_calls = 0;//holds size of number of calls' min heap
int arraysize_max_performance = 0;// holds size of performance score max heap
int arraysize_min_performance = 0;// holds size of performance score min heap

/*
    a function for copying
*/
void copy_values(employee *&oldarray, int incarraysize, employee *&newarray){
    for(int i=0;i<incarraysize;i++){
        newarray[i] = oldarray[i];
    }
}

/*
    for increasing keys of max number of calls heap
*/

void increase_key_max_calls(employee incomingarray[], employee incomingobj, int arraysize){
    int i;
    for(int j=0; j<arraysize; j++){
        if(incomingarray[j].ID == incomingobj.ID){
            i = j;
            break;
        }
    }
    incomingarray[i].number_of_calls = incomingarray[i].number_of_calls + incomingobj.number_of_calls;
    incomingarray[i].negative_feedback = incomingarray[i].negative_feedback + incomingobj.negative_feedback;
    incomingarray[i].positive_feedback = incomingarray[i].positive_feedback + incomingobj.positive_feedback;
    incomingarray[i].performance_score = 2 * incomingarray[i].number_of_calls + incomingarray[i].positive_feedback - incomingarray[i].negative_feedback;
    while(i>0 && incomingarray[parent(i)].number_of_calls < incomingarray[i].number_of_calls){
        swaps(incomingarray[i], incomingarray[parent(i)]);
        i = parent(i);
    }

}

/*
  for increasing keys of max performance score heap
*/

void increase_key_max_performance(employee incomingarray[], employee incomingobj, int arraysize){
    int i;
    for(int j=0; j<arraysize; j++){
        if(incomingarray[j].ID == incomingobj.ID){
            i = j;
            break;
        }
    }
    incomingarray[i].number_of_calls = incomingarray[i].number_of_calls + incomingobj.number_of_calls;
    incomingarray[i].negative_feedback = incomingarray[i].negative_feedback + incomingobj.negative_feedback;
    incomingarray[i].positive_feedback = incomingarray[i].positive_feedback + incomingobj.positive_feedback;
    incomingarray[i].performance_score = 2 * incomingarray[i].number_of_calls + incomingarray[i].positive_feedback - incomingarray[i].negative_feedback;
    while(i>0 && incomingarray[parent(i)].performance_score < incomingarray[i].performance_score){
        swaps(incomingarray[i], incomingarray[parent(i)]);
        i = parent(i);
    }
}

/*
  for increasing keys of min number of calls heap
*/

void increase_key_min_calls(employee incomingarray[], employee incomingobj, int arraysize){
    int i;
    for(int j=0; j<arraysize; j++){
        if(incomingarray[j].ID == incomingobj.ID){
            i = j;
            break;
        }
    }
    incomingarray[i].number_of_calls = incomingarray[i].number_of_calls + incomingobj.number_of_calls;
    incomingarray[i].negative_feedback = incomingarray[i].negative_feedback + incomingobj.negative_feedback;
    incomingarray[i].positive_feedback = incomingarray[i].positive_feedback + incomingobj.positive_feedback;
    incomingarray[i].performance_score = 2 * incomingarray[i].number_of_calls + incomingarray[i].positive_feedback - incomingarray[i].negative_feedback;
    min_heapify_calls(incomingarray, i , arraysize);
}

/*
  for increasing keys of min performance score heap
*/

void increase_key_min_performance(employee incomingarray[], employee incomingobj, int arraysize){
    int i;
    for(int j=0; j<arraysize; j++){
        if(incomingarray[j].ID == incomingobj.ID){
            i = j;
            break;
        }
    }
    incomingarray[i].number_of_calls = incomingarray[i].number_of_calls + incomingobj.number_of_calls;
    incomingarray[i].negative_feedback = incomingarray[i].negative_feedback + incomingobj.negative_feedback;
    incomingarray[i].positive_feedback = incomingarray[i].positive_feedback + incomingobj.positive_feedback;
    incomingarray[i].performance_score = 2 * incomingarray[i].number_of_calls + incomingarray[i].positive_feedback - incomingarray[i].negative_feedback;
    min_heapify_performance(incomingarray, i , arraysize);
}

/*
  extract function for max number of calls heap
*/

employee extract_max_calls(employee *&oldarray, int &arraysize){
    if(arraysize>0){
        employee object_tobe_returned;
        object_tobe_returned = oldarray[0];
        oldarray[0] = oldarray[arraysize-1];
        employee *newarray = new employee[--arraysize];
        copy_values(oldarray, arraysize, newarray);
        delete[] oldarray;
        oldarray = newarray;
        max_heapify_calls(oldarray, 0, arraysize);
        return object_tobe_returned;
    }
    else{
        cout<<"Heap is empty!!!"<<endl;
    }
}

/*
  extract function for max performance score heap
*/

employee extract_max_performance(employee *&oldarray, int &arraysize){
    if(arraysize>0){
        employee object_tobe_returned;
        object_tobe_returned = oldarray[0];
        oldarray[0] = oldarray[arraysize-1];
        employee *newarray = new employee[--arraysize];
        copy_values(oldarray, arraysize, newarray);
        delete[] oldarray;
        oldarray = newarray;
        max_heapify_performance(oldarray, 0, arraysize);
        return object_tobe_returned;
    }
    else{
        cout<<"Heap is empty!!!"<<endl;
    }
}

/*
  extract function for min number of calls heap
*/

employee extract_min_calls(employee *&oldarray, int &arraysize){
    if(arraysize>0){
        employee object_tobe_returned;
        object_tobe_returned = oldarray[0];
        oldarray[0] = oldarray[arraysize-1];
        arraysize--;
        employee *newarray = new employee[--arraysize];
        copy_values(oldarray, arraysize, newarray);
        delete[] oldarray;
        oldarray = newarray;
        min_heapify_calls(oldarray, 0, arraysize);
        return object_tobe_returned;
    }
    else{
        cout<<"Heap is empty!!!"<<endl;
    }
}

/*
  extract function for min performance score heap
*/

employee extract_min_performance(employee *&oldarray, int &arraysize){
    if(arraysize>0){
        employee object_tobe_returned;
        object_tobe_returned = oldarray[0];
        oldarray[0] = oldarray[arraysize-1];
        employee *newarray = new employee[--arraysize];
        copy_values(oldarray, arraysize, newarray);
        delete[] oldarray;
        oldarray = newarray;
        min_heapify_performance(oldarray, 0, arraysize);
        return object_tobe_returned;
    }
    else{
        cout<<"Heap is empty!!!"<<endl;
    }
}

/*
  insert function without update used for inserting day1.csv data and inserting elemnts to min heaps
*/


void insertdayone(employee *&oldarray, employee incomingobj, int &arraysize){
    for (int i=0; i < arraysize; i++){
        if ( oldarray[i].ID == incomingobj.ID){
            oldarray[i].number_of_calls += incomingobj.number_of_calls;
            oldarray[i].positive_feedback += incomingobj.positive_feedback;
            oldarray[i].negative_feedback += incomingobj.negative_feedback;
            oldarray[i].performance_score = oldarray[i].number_of_calls*2  + oldarray[i].positive_feedback - oldarray[i].negative_feedback;
            return;
        }
    }
    employee *newarray = new employee[arraysize+1];
    copy_values(oldarray, arraysize, newarray);
    delete[] oldarray;
    oldarray = newarray;
    oldarray[arraysize] = incomingobj;
    arraysize++;
}

/*
  inserts and heapifies for max number of calls heap
*/


void insert_max_calls(employee *&incomingarray, employee incomingobj, int &arraysize){
    for (int i=0; i < arraysize; i++){
        if ( incomingarray[i].ID == incomingobj.ID){
            incomingarray[i].number_of_calls += incomingobj.number_of_calls;
            incomingarray[i].positive_feedback += incomingobj.positive_feedback;
            incomingarray[i].negative_feedback += incomingobj.negative_feedback;
            incomingarray[i].performance_score = incomingarray[i].number_of_calls*2  + incomingarray[i].positive_feedback - incomingarray[i].negative_feedback;
            while(i>0 && incomingarray[parent(i)].number_of_calls < incomingarray[i].number_of_calls){
                swaps(incomingarray[i], incomingarray[parent(i)]);
                i = parent(i);
            }
            return;
        }
    }
    employee *newarray = new employee[arraysize+1];
    copy_values(incomingarray, arraysize, newarray);
    delete[] incomingarray;
    incomingarray = newarray;
    incomingarray[arraysize] = incomingobj;
    int i = arraysize;
    arraysize++;
    while(i>0 && incomingarray[parent(i)].number_of_calls < incomingarray[i].number_of_calls){
        swaps(incomingarray[i], incomingarray[parent(i)]);
        i = parent(i);
    }
}

/*
  inserts and heapifies for max performance score heap
*/


void insert_max_performance(employee *&incomingarray, employee incomingobj, int &arraysize){
    for (int i=0; i < arraysize; i++){
        if ( incomingarray[i].ID == incomingobj.ID){
            incomingarray[i].number_of_calls += incomingobj.number_of_calls;
            incomingarray[i].positive_feedback += incomingobj.positive_feedback;
            incomingarray[i].negative_feedback += incomingobj.negative_feedback;
            incomingarray[i].performance_score = incomingarray[i].number_of_calls*2  + incomingarray[i].positive_feedback - incomingarray[i].negative_feedback;
            while(i>0 && incomingarray[parent(i)].performance_score < incomingarray[i].performance_score){
                swaps(incomingarray[i], incomingarray[parent(i)]);
                i = parent(i);
            }
            return;
        }
    }
    employee *newarray = new employee[arraysize+1];
    copy_values(incomingarray, arraysize, newarray);
    delete[] incomingarray;
    incomingarray = newarray;
    incomingarray[arraysize] = incomingobj;
    int i = arraysize;
    arraysize++;
    while(i>0 && incomingarray[parent(i)].performance_score < incomingarray[i].performance_score){
        swaps(incomingarray[i], incomingarray[parent(i)]);
        i = parent(i);
    }
}


int main()
{
    freopen("day1.csv", "r", stdin);    //opens up the day1.csv file

    int a,b,c,d;

    employee *array_of_max_calls = new employee[arraysize_max_calls];   //creates max calls array
    employee *array_of_min_calls = new employee[arraysize_min_calls];   //creates min calls array
    employee *array_of_max_performance = new employee[arraysize_max_performance];   //creates max performance array
    employee *array_of_min_performance = new employee[arraysize_min_performance];   //creates max performance array

    while(!feof(stdin) && scanf("%d, %d, %d, %d", &a, &b, &c, &d) ){    //checks if end of file is reached and reads data from file
        employee tmpemployee;   // temporary employee object
        tmpemployee.ID = a;     //assigns ID
        tmpemployee.number_of_calls = b;    //assigns number of calls
        tmpemployee.positive_feedback = c;  //assigns positive feedback
        tmpemployee.negative_feedback = d;  //assigns negative feedback
        tmpemployee.performance_score = 2*b+c-d;    //calculates performance score
        insertdayone(array_of_max_calls, tmpemployee, arraysize_max_calls); //inserts object to max calls array
        insertdayone(array_of_min_calls, tmpemployee, arraysize_min_calls); //inserts object to min calls array
        insertdayone(array_of_max_performance, tmpemployee, arraysize_max_performance); //inserts object to max performance array
        insertdayone(array_of_min_performance, tmpemployee, arraysize_min_performance); //inserts object to min performance array
    }



    build_max_heap_calls(array_of_max_calls, arraysize_max_calls);  //builds max calls heap
    build_max_heap_performance(array_of_max_performance, arraysize_max_performance);    //builds max performance heap
    build_min_heap_calls(array_of_min_calls, arraysize_min_calls);  //builds min calls heap
    build_min_heap_performance(array_of_min_performance, arraysize_min_performance);    //builds min calls heap

    /*
        temporary employee arrays that keeps values to be printed and inserted after
    */
    employee tobe_printed_max_performance[4];
    employee tobe_printed_min_performance[4];
    employee tobe_printed_max_calls[4];
    employee tobe_printed_min_calls[4];

    /*
        assigning values to temporary employee arrays and inserts back after extraction
    */

    for(int i=0;i<4;i++){
        tobe_printed_max_performance[i] = extract_max_performance(array_of_max_performance, arraysize_max_performance);
    }
    for(int i=0;i<4;i++){
        insert_max_performance(array_of_max_performance, tobe_printed_max_performance[i], arraysize_max_performance);
    }

    for(int i=0;i<4;i++){
        tobe_printed_max_calls[i] = extract_max_calls(array_of_max_calls, arraysize_max_calls);
    }
    for(int i=0;i<4;i++){
        insert_max_calls(array_of_max_calls, tobe_printed_max_calls[i], arraysize_max_calls);
    }

    /*
        uses temporary array values to print
    */

    cout<<"AFTER DAY-1"<<endl;
    cout<<"BEST PERFORMANCE  : ID="<<tobe_printed_max_performance[1].ID<<" and PS="<<tobe_printed_max_performance[1].performance_score<<"   ,  ID="<<tobe_printed_max_performance[2].ID<<" and PS="<<tobe_printed_max_performance[2].performance_score<<"   ,  ID="<<tobe_printed_max_performance[3].ID<<" and PS="<<tobe_printed_max_performance[3].performance_score<<endl;
    cout<<"MAXIMUM CALLS     : ID="<<tobe_printed_max_calls[1].ID<<" and CALLS="<<tobe_printed_max_calls[1].number_of_calls<<"   ,  ID="<<tobe_printed_max_calls[2].ID<<" and CALLS="<<tobe_printed_max_calls[2].number_of_calls<<"   ,  ID="<<tobe_printed_max_calls[3].ID<<" and CALLS="<<tobe_printed_max_calls[3].number_of_calls<<endl;



    freopen("day2.csv", "r", stdin);    //opens up the file
    while(!feof(stdin) && scanf("%d, %d, %d, %d", &a,&b, &c, &d) ){ //reads values and checks if end of file is reached
        employee tmpemployee;
        tmpemployee.ID = a;
        tmpemployee.number_of_calls = b;
        tmpemployee.positive_feedback = c;
        tmpemployee.negative_feedback = d;
        tmpemployee.performance_score = 2*b+c-d;
        insert_max_calls(array_of_max_calls, tmpemployee, arraysize_max_calls); //inserts object to max calls heap and heapifies
        insertdayone(array_of_min_calls, tmpemployee, arraysize_min_calls); //inserts object to min calls heap and it does not heapify
        insert_max_performance(array_of_max_performance, tmpemployee, arraysize_max_performance);   //inserts object to max performance heap and heapifies
        insertdayone(array_of_min_performance, tmpemployee, arraysize_min_performance); //inserts object to min performance heap and does not heapifies
    }

    for(int i=0;i<4;i++){
        tobe_printed_max_performance[i] = extract_max_performance(array_of_max_performance, arraysize_max_performance);
    }
    for(int i=0;i<4;i++){
        insert_max_performance(array_of_max_performance, tobe_printed_max_performance[i], arraysize_max_performance);
    }


    for(int i=0;i<4;i++){
        tobe_printed_max_calls[i] = extract_max_calls(array_of_max_calls, arraysize_max_calls);
    }
    for(int i=0;i<4;i++){
        insert_max_calls(array_of_max_calls, tobe_printed_max_calls[i], arraysize_max_calls);
    }

    cout<<"AFTER DAY-2"<<endl;
    cout<<"BEST PERFORMANCE  : ID="<<tobe_printed_max_performance[1].ID<<" and PS="<<tobe_printed_max_performance[1].performance_score<<"   ,  ID="<<tobe_printed_max_performance[2].ID<<" and PS="<<tobe_printed_max_performance[2].performance_score<<"   ,  ID="<<tobe_printed_max_performance[3].ID<<" and PS="<<tobe_printed_max_performance[3].performance_score<<endl;
    cout<<"MAXIMUM CALLS     : ID="<<tobe_printed_max_calls[1].ID<<" and CALLS="<<tobe_printed_max_calls[1].number_of_calls<<"   ,  ID="<<tobe_printed_max_calls[2].ID<<" and CALLS="<<tobe_printed_max_calls[2].number_of_calls<<"   ,  ID="<<tobe_printed_max_calls[3].ID<<" and CALLS="<<tobe_printed_max_calls[3].number_of_calls<<endl;


    /*
        SAME OPERATIONS AFTER HERE
    */





    freopen("day3.csv", "r", stdin);
    while(!feof(stdin) && scanf("%d, %d, %d, %d", &a,&b, &c, &d) ){
        employee tmpemployee;
        tmpemployee.ID = a;
        tmpemployee.number_of_calls = b;
        tmpemployee.positive_feedback = c;
        tmpemployee.negative_feedback = d;
        tmpemployee.performance_score = 2*b+c-d;
        insert_max_calls(array_of_max_calls, tmpemployee, arraysize_max_calls);
        insertdayone(array_of_min_calls, tmpemployee, arraysize_min_calls);
        insert_max_performance(array_of_max_performance, tmpemployee, arraysize_max_performance);
        insertdayone(array_of_min_performance, tmpemployee, arraysize_min_performance);
    }

    for(int i=0;i<4;i++){
        tobe_printed_max_performance[i] = extract_max_performance(array_of_max_performance, arraysize_max_performance);
    }
    for(int i=0;i<4;i++){
        insert_max_performance(array_of_max_performance, tobe_printed_max_performance[i], arraysize_max_performance);
    }


    for(int i=0;i<4;i++){
        tobe_printed_max_calls[i] = extract_max_calls(array_of_max_calls, arraysize_max_calls);
    }
    for(int i=0;i<4;i++){
        insert_max_calls(array_of_max_calls, tobe_printed_max_calls[i], arraysize_max_calls);
    }

    cout<<"AFTER DAY-3"<<endl;
    cout<<"BEST PERFORMANCE  : ID="<<tobe_printed_max_performance[1].ID<<" and PS="<<tobe_printed_max_performance[1].performance_score<<"   ,  ID="<<tobe_printed_max_performance[2].ID<<" and PS="<<tobe_printed_max_performance[2].performance_score<<"   ,  ID="<<tobe_printed_max_performance[3].ID<<" and PS="<<tobe_printed_max_performance[3].performance_score<<endl;
    cout<<"MAXIMUM CALLS     : ID="<<tobe_printed_max_calls[0].ID<<" and CALLS="<<tobe_printed_max_calls[0].number_of_calls<<"   ,  ID="<<tobe_printed_max_calls[1].ID<<" and CALLS="<<tobe_printed_max_calls[1].number_of_calls<<"   ,  ID="<<tobe_printed_max_calls[2].ID<<" and CALLS="<<tobe_printed_max_calls[2].number_of_calls<<endl;

    freopen("day4.csv", "r", stdin);
    while(!feof(stdin) && scanf("%d, %d, %d, %d", &a,&b, &c, &d) ){
        employee tmpemployee;
        tmpemployee.ID = a;
        tmpemployee.number_of_calls = b;
        tmpemployee.positive_feedback = c;
        tmpemployee.negative_feedback = d;
        tmpemployee.performance_score = 2*b+c-d;
        insert_max_calls(array_of_max_calls, tmpemployee, arraysize_max_calls);
        insertdayone(array_of_min_calls, tmpemployee, arraysize_min_calls);
        insert_max_performance(array_of_max_performance, tmpemployee, arraysize_max_performance);
        insertdayone(array_of_min_performance, tmpemployee, arraysize_min_performance);
    }

    for(int i=0;i<3;i++){
        tobe_printed_max_performance[i] = extract_max_performance(array_of_max_performance, arraysize_max_performance);
    }
    for(int i=0;i<3;i++){
        insert_max_performance(array_of_max_performance, tobe_printed_max_performance[i], arraysize_max_performance);
    }



    for(int i=0;i<3;i++){
        tobe_printed_max_calls[i] = extract_max_calls(array_of_max_calls, arraysize_max_calls);
    }
    for(int i=0;i<3;i++){
        insert_max_calls(array_of_max_calls, tobe_printed_max_calls[i], arraysize_max_calls);
    }

    cout<<"AFTER DAY-4"<<endl;
    cout<<"BEST PERFORMANCE  : ID="<<tobe_printed_max_performance[0].ID<<" and PS="<<tobe_printed_max_performance[0].performance_score<<"   ,  ID="<<tobe_printed_max_performance[1].ID<<" and PS="<<tobe_printed_max_performance[1].performance_score<<"   ,  ID="<<tobe_printed_max_performance[2].ID<<" and PS="<<tobe_printed_max_performance[2].performance_score<<endl;
    cout<<"MAXIMUM CALLS     : ID="<<tobe_printed_max_calls[0].ID<<" and CALLS="<<tobe_printed_max_calls[0].number_of_calls<<"   ,  ID="<<tobe_printed_max_calls[1].ID<<" and CALLS="<<tobe_printed_max_calls[1].number_of_calls<<"   ,  ID="<<tobe_printed_max_calls[2].ID<<" and CALLS="<<tobe_printed_max_calls[2].number_of_calls<<endl;

    freopen("day5.csv", "r", stdin);
    while(!feof(stdin) && scanf("%d, %d, %d, %d", &a,&b, &c, &d) ){
        employee tmpemployee;
        tmpemployee.ID = a;
        tmpemployee.number_of_calls = b;
        tmpemployee.positive_feedback = c;
        tmpemployee.negative_feedback = d;
        tmpemployee.performance_score = 2*b+c-d;
        insert_max_calls(array_of_max_calls, tmpemployee, arraysize_max_calls);
        insertdayone(array_of_min_calls, tmpemployee, arraysize_min_calls);
        insert_max_performance(array_of_max_performance, tmpemployee, arraysize_max_performance);
        insertdayone(array_of_min_performance, tmpemployee, arraysize_min_performance);
    }

    for(int i=0;i<3;i++){
        tobe_printed_max_performance[i] = extract_max_performance(array_of_max_performance, arraysize_max_performance);
    }
    for(int i=0;i<3;i++){
        insert_max_performance(array_of_max_performance, tobe_printed_max_performance[i], arraysize_max_performance);
    }
    for(int i=0;i<3;i++){
        tobe_printed_max_calls[i] = extract_max_calls(array_of_max_calls, arraysize_max_calls);
    }
    for(int i=0;i<3;i++){
        insert_max_calls(array_of_max_calls, tobe_printed_max_calls[i], arraysize_max_calls);
    }

    cout<<"AFTER DAY-5"<<endl;
    cout<<"BEST PERFORMANCE  : ID="<<tobe_printed_max_performance[0].ID<<" and PS="<<tobe_printed_max_performance[0].performance_score<<"   ,  ID="<<tobe_printed_max_performance[1].ID<<" and PS="<<tobe_printed_max_performance[1].performance_score<<"   ,  ID="<<tobe_printed_max_performance[2].ID<<" and PS="<<tobe_printed_max_performance[2].performance_score<<endl;
    cout<<"MAXIMUM CALLS     : ID="<<tobe_printed_max_calls[0].ID<<" and CALLS="<<tobe_printed_max_calls[0].number_of_calls<<"   ,  ID="<<tobe_printed_max_calls[1].ID<<" and CALLS="<<tobe_printed_max_calls[1].number_of_calls<<"   ,  ID="<<tobe_printed_max_calls[2].ID<<" and CALLS="<<tobe_printed_max_calls[2].number_of_calls<<endl;

    freopen("day6.csv", "r", stdin);
    while(!feof(stdin) && scanf("%d, %d, %d, %d", &a,&b, &c, &d) ){
        employee tmpemployee;
        tmpemployee.ID = a;
        tmpemployee.number_of_calls = b;
        tmpemployee.positive_feedback = c;
        tmpemployee.negative_feedback = d;
        tmpemployee.performance_score = 2*b+c-d;
        insert_max_calls(array_of_max_calls, tmpemployee, arraysize_max_calls);
        insertdayone(array_of_min_calls, tmpemployee, arraysize_min_calls);
        insert_max_performance(array_of_max_performance, tmpemployee, arraysize_max_performance);
        insertdayone(array_of_min_performance, tmpemployee, arraysize_min_performance);
    }

    for(int i=0;i<3;i++){
        tobe_printed_max_performance[i] = extract_max_performance(array_of_max_performance, arraysize_max_performance);
    }
    for(int i=0;i<3;i++){
        insert_max_performance(array_of_max_performance, tobe_printed_max_performance[i], arraysize_max_performance);
    }
    for(int i=0;i<3;i++){
        tobe_printed_max_calls[i] = extract_max_calls(array_of_max_calls, arraysize_max_calls);
    }
    for(int i=0;i<3;i++){
        insert_max_calls(array_of_max_calls, tobe_printed_max_calls[i], arraysize_max_calls);
    }

    cout<<"AFTER DAY-6"<<endl;
    cout<<"BEST PERFORMANCE  : ID="<<tobe_printed_max_performance[0].ID<<" and PS="<<tobe_printed_max_performance[0].performance_score<<"   ,  ID="<<tobe_printed_max_performance[1].ID<<" and PS="<<tobe_printed_max_performance[1].performance_score<<"   ,  ID="<<tobe_printed_max_performance[2].ID<<" and PS="<<tobe_printed_max_performance[2].performance_score<<endl;
    cout<<"MAXIMUM CALLS     : ID="<<tobe_printed_max_calls[0].ID<<" and CALLS="<<tobe_printed_max_calls[0].number_of_calls<<"   ,  ID="<<tobe_printed_max_calls[1].ID<<" and CALLS="<<tobe_printed_max_calls[1].number_of_calls<<"   ,  ID="<<tobe_printed_max_calls[2].ID<<" and CALLS="<<tobe_printed_max_calls[2].number_of_calls<<endl;

    freopen("day7.csv", "r", stdin);
    while(!feof(stdin) && scanf("%d, %d, %d, %d", &a,&b, &c, &d) ){
        employee tmpemployee;
        tmpemployee.ID = a;
        tmpemployee.number_of_calls = b;
        tmpemployee.positive_feedback = c;
        tmpemployee.negative_feedback = d;
        tmpemployee.performance_score = 2*b+c-d;
        insert_max_calls(array_of_max_calls, tmpemployee, arraysize_max_calls);
        insertdayone(array_of_min_calls, tmpemployee, arraysize_min_calls);
        insert_max_performance(array_of_max_performance, tmpemployee, arraysize_max_performance);
        insertdayone(array_of_min_performance, tmpemployee, arraysize_min_performance);
    }

    for(int i=0;i<3;i++){
        tobe_printed_max_performance[i] = extract_max_performance(array_of_max_performance, arraysize_max_performance);
    }
    for(int i=0;i<3;i++){
        insert_max_performance(array_of_max_performance, tobe_printed_max_performance[i], arraysize_max_performance);
    }

    for(int i=0;i<3;i++){
        tobe_printed_max_calls[i] = extract_max_calls(array_of_max_calls, arraysize_max_calls);
    }
    for(int i=0;i<3;i++){
        insert_max_calls(array_of_max_calls, tobe_printed_max_calls[i], arraysize_max_calls);
    }

    cout<<"AFTER DAY-7"<<endl;
    cout<<"BEST PERFORMANCE  : ID="<<tobe_printed_max_performance[0].ID<<" and PS="<<tobe_printed_max_performance[0].performance_score<<"   ,  ID="<<tobe_printed_max_performance[1].ID<<" and PS="<<tobe_printed_max_performance[1].performance_score<<"   ,  ID="<<tobe_printed_max_performance[2].ID<<" and PS="<<tobe_printed_max_performance[2].performance_score<<endl;
    cout<<"MAXIMUM CALLS     : ID="<<tobe_printed_max_calls[0].ID<<" and CALLS="<<tobe_printed_max_calls[0].number_of_calls<<"   ,  ID="<<tobe_printed_max_calls[1].ID<<" and CALLS="<<tobe_printed_max_calls[1].number_of_calls<<"   ,  ID="<<tobe_printed_max_calls[2].ID<<" and CALLS="<<tobe_printed_max_calls[2].number_of_calls<<endl;

    freopen("day8.csv", "r", stdin);
    while(!feof(stdin) && scanf("%d, %d, %d, %d", &a,&b, &c, &d) ){
        employee tmpemployee;
        tmpemployee.ID = a;
        tmpemployee.number_of_calls = b;
        tmpemployee.positive_feedback = c;
        tmpemployee.negative_feedback = d;
        tmpemployee.performance_score = 2*b+c-d;
        insert_max_calls(array_of_max_calls, tmpemployee, arraysize_max_calls);
        insertdayone(array_of_min_calls, tmpemployee, arraysize_min_calls);
        insert_max_performance(array_of_max_performance, tmpemployee, arraysize_max_performance);
        insertdayone(array_of_min_performance, tmpemployee, arraysize_min_performance);
    }

    for(int i=0;i<3;i++){
        tobe_printed_max_performance[i] = extract_max_performance(array_of_max_performance, arraysize_max_performance);
    }
    for(int i=0;i<3;i++){
        insert_max_performance(array_of_max_performance, tobe_printed_max_performance[i], arraysize_max_performance);
    }



    for(int i=0;i<3;i++){
        tobe_printed_max_calls[i] = extract_max_calls(array_of_max_calls, arraysize_max_calls);
    }
    for(int i=0;i<3;i++){
        insert_max_calls(array_of_max_calls, tobe_printed_max_calls[i], arraysize_max_calls);
    }


    cout<<"AFTER DAY-8"<<endl;
    cout<<"BEST PERFORMANCE  : ID="<<tobe_printed_max_performance[0].ID<<" and PS="<<tobe_printed_max_performance[0].performance_score<<"   ,  ID="<<tobe_printed_max_performance[1].ID<<" and PS="<<tobe_printed_max_performance[1].performance_score<<"   ,  ID="<<tobe_printed_max_performance[2].ID<<" and PS="<<tobe_printed_max_performance[2].performance_score<<endl;
    cout<<"MAXIMUM CALLS     : ID="<<tobe_printed_max_calls[0].ID<<" and CALLS="<<tobe_printed_max_calls[0].number_of_calls<<"   ,  ID="<<tobe_printed_max_calls[1].ID<<" and CALLS="<<tobe_printed_max_calls[1].number_of_calls<<"   ,  ID="<<tobe_printed_max_calls[2].ID<<" and CALLS="<<tobe_printed_max_calls[2].number_of_calls<<endl;

    freopen("day9.csv", "r", stdin);
    while(!feof(stdin) && scanf("%d, %d, %d, %d", &a,&b, &c, &d) ){
        employee tmpemployee;
        tmpemployee.ID = a;
        tmpemployee.number_of_calls = b;
        tmpemployee.positive_feedback = c;
        tmpemployee.negative_feedback = d;
        tmpemployee.performance_score = 2*b+c-d;
        insert_max_calls(array_of_max_calls, tmpemployee, arraysize_max_calls);
        insertdayone(array_of_min_calls, tmpemployee, arraysize_min_calls);
        insert_max_performance(array_of_max_performance, tmpemployee, arraysize_max_performance);
        insertdayone(array_of_min_performance, tmpemployee, arraysize_min_performance);
    }

    for(int i=0;i<3;i++){
        tobe_printed_max_performance[i] = extract_max_performance(array_of_max_performance, arraysize_max_performance);
    }
    for(int i=0;i<3;i++){
        insert_max_performance(array_of_max_performance, tobe_printed_max_performance[i], arraysize_max_performance);
    }


    for(int i=0;i<3;i++){
        tobe_printed_max_calls[i] = extract_max_calls(array_of_max_calls, arraysize_max_calls);
    }
    for(int i=0;i<3;i++){
        insert_max_calls(array_of_max_calls, tobe_printed_max_calls[i], arraysize_max_calls);
    }


    cout<<"AFTER DAY-9"<<endl;
    cout<<"BEST PERFORMANCE  : ID="<<tobe_printed_max_performance[0].ID<<" and PS="<<tobe_printed_max_performance[0].performance_score<<"   ,  ID="<<tobe_printed_max_performance[1].ID<<" and PS="<<tobe_printed_max_performance[1].performance_score<<"   ,  ID="<<tobe_printed_max_performance[2].ID<<" and PS="<<tobe_printed_max_performance[2].performance_score<<endl;
    cout<<"MAXIMUM CALLS     : ID="<<tobe_printed_max_calls[0].ID<<" and CALLS="<<tobe_printed_max_calls[0].number_of_calls<<"   ,  ID="<<tobe_printed_max_calls[1].ID<<" and CALLS="<<tobe_printed_max_calls[1].number_of_calls<<"   ,  ID="<<tobe_printed_max_calls[2].ID<<" and CALLS="<<tobe_printed_max_calls[2].number_of_calls<<endl;

    freopen("day10.csv", "r", stdin);
    while(!feof(stdin) && scanf("%d, %d, %d, %d", &a,&b, &c, &d) ){
        employee tmpemployee;
        tmpemployee.ID = a;
        tmpemployee.number_of_calls = b;
        tmpemployee.positive_feedback = c;
        tmpemployee.negative_feedback = d;
        tmpemployee.performance_score = 2*b+c-d;
        insert_max_calls(array_of_max_calls, tmpemployee, arraysize_max_calls);
        insertdayone(array_of_min_calls, tmpemployee, arraysize_min_calls);
        insert_max_performance(array_of_max_performance, tmpemployee, arraysize_max_performance);
        insertdayone(array_of_min_performance, tmpemployee, arraysize_min_performance);
    }

    for(int i=0;i<3;i++){
        tobe_printed_max_performance[i] = extract_max_performance(array_of_max_performance, arraysize_max_performance);
    }
    for(int i=0;i<3;i++){
        insert_max_performance(array_of_max_performance, tobe_printed_max_performance[i], arraysize_max_performance);
    }

    for(int i=0;i<3;i++){
        tobe_printed_max_calls[i] = extract_max_calls(array_of_max_calls, arraysize_max_calls);
    }
    for(int i=0;i<3;i++){
        insert_max_calls(array_of_max_calls, tobe_printed_max_calls[i], arraysize_max_calls);
    }


    cout<<"AFTER DAY-10"<<endl;
    cout<<"BEST PERFORMANCE  : ID="<<tobe_printed_max_performance[0].ID<<" and PS="<<tobe_printed_max_performance[0].performance_score<<"   ,  ID="<<tobe_printed_max_performance[1].ID<<" and PS="<<tobe_printed_max_performance[1].performance_score<<"   ,  ID="<<tobe_printed_max_performance[2].ID<<" and PS="<<tobe_printed_max_performance[2].performance_score<<endl;
    cout<<"MAXIMUM CALLS     : ID="<<tobe_printed_max_calls[0].ID<<" and CALLS="<<tobe_printed_max_calls[0].number_of_calls<<"   ,  ID="<<tobe_printed_max_calls[1].ID<<" and CALLS="<<tobe_printed_max_calls[1].number_of_calls<<"   ,  ID="<<tobe_printed_max_calls[2].ID<<" and CALLS="<<tobe_printed_max_calls[2].number_of_calls<<endl;


    build_min_heap_calls(array_of_min_calls,arraysize_min_calls);
    build_min_heap_performance(array_of_min_performance, arraysize_min_performance);

    for(int i=0;i<3;i++){
        tobe_printed_min_performance[i] = extract_min_performance(array_of_min_performance, arraysize_min_performance);
    }
    for(int i=0;i<3;i++){
        insertdayone(array_of_min_performance, tobe_printed_min_performance[i], arraysize_min_performance);
    }

    for(int i=0;i<3;i++){
        tobe_printed_min_calls[i] = extract_min_calls(array_of_min_calls, arraysize_min_calls);
    }
    for(int i=0;i<3;i++){
        insertdayone(array_of_min_calls, tobe_printed_min_calls[i], arraysize_min_calls);
    }


    cout<<"WORST PERFORMANCE : ID="<<tobe_printed_min_performance[0].ID<<" and PS="<<tobe_printed_min_performance[0].performance_score<<"   ,  ID="<<tobe_printed_min_performance[1].ID<<" and PS="<<tobe_printed_min_performance[1].performance_score<<"   ,  ID="<<tobe_printed_min_performance[2].ID<<" and PS="<<tobe_printed_min_performance[2].performance_score<<endl;
    cout<<"MINIMUM CALLS     : ID="<<tobe_printed_min_calls[0].ID<<" and CALLS="<<tobe_printed_min_calls[0].number_of_calls<<"   ,  ID="<<tobe_printed_min_calls[1].ID<<" and CALLS="<<tobe_printed_min_calls[1].number_of_calls<<"   ,  ID="<<tobe_printed_min_calls[2].ID<<" and CALLS="<<tobe_printed_min_calls[2].number_of_calls<<endl;


    return 0;
}
