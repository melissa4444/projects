//
//  main.cpp
//  creditCard
//
//  Created by Melissa Estrada on 3/9/19.
//
//
#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

bool isvalidcc(const string& cardNum);


int doublingSecDig(long long num);
int doubleDigit(int num);
int addOddDig(long long num);

int main()
{
    //
    // PLEASE DO NOT CHANGE function main
    //
    vector<string> cardnumbers = {
        "371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
        "4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
        "5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
        "4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
        "5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
        "372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
        "4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
        "5556551555555557", "6011316011016011"
    };
    
    int i;
    vector<string>::iterator itr;
    
    for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) {
        cout << setw(2)  << i << " "
        << setw(17) << *itr
        << ((isvalidcc(*itr)) ? " is valid" : " is not valid") << endl;
    }
    
    return 0;
}

bool isvalidcc(const string& cardNum) {
    int length = cardNum.length();
    
    if ((length >= 13) || (length <= 16)) {
        //checks if starting numbers are valid
        switch (cardNum.at(0))
        {
            case '3':
                if (cardNum.at(1) != '7') return false;
            case '4':
            case '5':
            case '6':
                break;
            default:
                return false;
        }
    }
    else {
        return false;
    }
    
    long long tempNum;
    
    stringstream s(cardNum);
    s >> tempNum;
    
    int evenTotal, oddTotal;
    
    evenTotal = doublingSecDig(tempNum);
    oddTotal = addOddDig(tempNum);
    
    int total = evenTotal + oddTotal;
    
    return total % 10 == 0;
}

int doublingSecDig(long long num) {
    int sum = 0;
    while (num != 0){
        num = num / 10;
        sum += doubleDigit((num % 10) * 2);
        num = num / 10;
    }
    return sum;
}


int doubleDigit(int num) {
    int newNum = 0;
    while (num != 0) {
        newNum += num % 10;
        num = num / 10;
    }
    return newNum;
    
}

int addOddDig(long long num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num = num / 100;
        
    }
    return sum;
}
