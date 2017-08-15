#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

/*********** notname **********
      Purpose: An string, str, is looked up this str whether contain
        integer from 0 to 9.
        if it contains integer 0-9, then return 1.
        if it does not contains integer 0-9, then return 0.
 
      Returns: return integer 1 or 0.
***********************************/

int notname (string str){
    int index = 0;
    int strlength = 0;
    // loop to get the length of the string
    while (str[index]){
        strlength++;     //increment length
        index++;
    }  //while
    int pos = 0;
    //loop to check string do not contain integer 0-9
    while (pos < strlength){
        if (str[pos] >= '0' && str[pos] <= '9'){
            return 1;     //return 1 if there exist integer 0-9
        }
        pos++;             //increment position
    } //while
    return 0;             //return 0 if there does not exist integer 0-9
}

const int maximum = 10;
string person[maximum];
int voters = 0;     //number of voters
int valid = 0;      //valid of votes
int sumcan = 0;     //number of candidates
int spoilt = 0;    //valid of votes
int arr[maximum];
int open = 1;      //a control

/*********** readVotes ***********
      Purpose: Contains integer value, to read candidates and votes, to
           record number of candidates, valid and invalid of votes,
           and they are votes.
 
       Returns: Null.
************************************/

void readVotes(int value){
    int index = 0;
    int num = 0;   //number
    string str;
    int total = 0;   //the sum of the string of integer
    int argument = 0;
    while (getline (cin, str)){
        //loop to read every line of string
        // to read candidate
        if (notname(str) == 0 && open == 1){  //if read in candidate
            person[index] = str;
            sumcan++;    //increment number of candidates
            index++;
        }  //if
        else {
            open = 0;
            if (value == 0){
                argument = sumcan;
            }  //if
            else{argument = value;}
            int count = 0;    //counter
            stringstream ss(str);
            total = 0;
            //if read in votes
            while (ss >> num){
                //loop to read in integer
                count++;
                total = total + num;
            }  //while
            if (count != sumcan){
                spoilt++;     //increment invalid votes
            }  //if
            else if (total > argument){
                spoilt++;    //increment invalid votes
            }
            else {
            int pos = 0;
            stringstream sss(str);
            // read in votes again
            while (sss >> num){
                //loop to read in integer again
                arr[pos] = arr[pos]+ num;
                pos++;
            }  //while
            valid++;    //increment valid votes
            }
        }
    } //while
    voters = valid + spoilt;     //to sum up the voters.
}

/*********** printResults ***********
      Purpose: to print sumvote, valid of votes, invalid of votes,
           and votes correspond candidate
 
      Returns: Null
 ************************************/

void printResults(){
    cout << "Number of voters: " << voters << endl;
    cout << "Number of valid ballots: " << valid << endl;
    cout << "Number of spoilt ballots: " << spoilt << endl;
    cout << endl;
    cout << "Candidate      Score" << endl << endl;
    int pos = 0;
    while (pos < sumcan){
        // loop to print the candidate and they are votes
        cout << setw(15) << left << person[pos] << setw(3) << right << arr[pos] << endl;
        pos++;  //increment of position
    }   //while
}

/*********** main ***********
     Purpose: First to determine its there exist argument. And then
          to run readVotes and printResults function.
          if there exist argument, then pass this arugument in readVotes.
          if there is not exist argument, then pass 0 in readVotes.
 
     Returns: Null
************************************/

int main(int argc, const char * argv[]) {
    int myvalue = 0;    //integer
    if (argc != 1){
        istringstream iss(argv[1]);
        iss >> myvalue;   //read in integer
    } //if
    readVotes(myvalue);   //pass myvalue in readVotes
    printResults();
}
