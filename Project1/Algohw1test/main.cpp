#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <sstream>


using namespace std;

struct timestamp{
    int year, month, day, hour, minute, second, milisecond;
    bool operator>(const timestamp& b){
        if ( year > b.year) return true;
        if (year  == b.year){
            if ( month > b.month ) return true;
            if (month == b.month){
                if ( day > b.day) return true;
                if ( day == b.day) {
                    if (hour > b.hour ) return true;
                    if (hour == b.hour){
                        if (minute > b.minute)return true;
                        if (minute == b.minute){
                            if (second > b.second)return true;
                            if (second == b.second){
                                return milisecond >= b.milisecond;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};

struct node{
    static int comparision_type;
    float price;
    string print_value;
    timestamp ts;
    bool operator>(const node& b){
        if ( comparision_type == 0){
            return ts > b.ts;
        }
        if ( comparision_type == 1){
            return price > b.price;
        }
    }
    void print(){
        cout << print_value << endl;
    }

};

void insertion_sort(vector<node> &incomingvector){
    for (int j=1;j<incomingvector.size();j++){
        int i = j-1;
        while(i>=0 && incomingvector[i] > incomingvector[j]){
            swap(incomingvector[i],incomingvector[j]);
            i--;
            j--;
        }
    }
}

timestamp parse_ts(string t){
    timestamp ts;
    for(int i=0; i< t.length(); ++i)
        if ( t[i]=='-' || t[i] == ':' || t[i]=='.')
            t[i] = ' ';
    stringstream new_buf(t);
    new_buf >> ts.year >> ts.month >> ts.day >> ts.hour >> ts.minute >> ts.second >> ts.milisecond;
    return ts;
}

node parse(string buf){
    node res;
    res.print_value = buf;
    stringstream new_buf(buf);
    char dummy[30];
    new_buf.getline( dummy, 30,  ',');
    res.ts = parse_ts( string(dummy) ) ;
    for(int i=0; i < 2; ++i){
        new_buf.getline( dummy, 30,  ',');
        res.price = atof(dummy);
    }
    return res;

}

void merge(vector<node> &incomingvector, int s, int m, int e){
    vector<node> l, r;
    for(int i=s;i<=m;i++){
        l.push_back(incomingvector[i]);
    }
    for(int j=m+1;j<=e;j++){
        r.push_back(incomingvector[j]);
    }
    int i = 0;
    int j = 0;
    int k = s;
    while ( i < l.size() && j < r.size() ){
        if( r[j]>l[i] ){
            incomingvector[k] = l[i++];
        }
        else{
            incomingvector[k] = r[j++];
        }
        k++;
    }
    while ( i < l.size()){
        incomingvector[k++] = l[i++];
    }
    while ( j < r.size()){
        incomingvector[k++] = r[j++];
    }
}

void merge_sort(vector<node> &incomingvector, int s, int e){
    if(s<e){
        int m = (s+e)/2;
        merge_sort( incomingvector,  s,  m);
        merge_sort( incomingvector,  m + 1,  e);
        merge( incomingvector,  s,  m,  e);
    }
}
int node::comparision_type = 0;

int main(int argc, char** argv)
{


    if(strcmp(argv[4],"t") == 0){
        node::comparision_type = 0;
    }

    if(strcmp(argv[4],"p") == 0){
        node::comparision_type = 1;
    }


    int number_of_lines = atoi(argv[6]);

    freopen("log_inf.csv", "r", stdin);
    vector<node> data(number_of_lines);

    char buf[10000];
    cin.getline(buf, 10000);

    string labels(buf);
    for(int i=0; i < number_of_lines; i++) {
        cin.getline(buf,10000);
        data[i] = parse(string(buf));
    }

    clock_t t;
    t = clock();
    printf ("Calculating...\n");

    if(strcmp(argv[2],"m") == 0){
        merge_sort(data, 0 , data.size()-1);
    }
    if(strcmp(argv[2],"i") == 0){
        insertion_sort(data);
    }

    t = clock() - t;
    printf ("It took me %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);


    freopen("sorted.csv", "w", stdout);
    cout << labels << endl;
    for(int i=0; i< data.size(); ++i){
        data[i].print();
    }

    return 0;
}
