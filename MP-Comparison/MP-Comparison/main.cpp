//
//  main.cpp
//  MP-Comparison
//
//  Created by Hélder Gonçalves on 26/11/15.
//  Copyright © 2015 Hélder Gonçalves. All rights reserved.
//
#include <NTL/ZZ.h>
#include <NTL/RR.h>

#include <iostream>
#include "timer.h"

#define N 3000
#define NUM_REP 5

using namespace NTL;
using namespace std;


void cleanCache(){
    long *matrix = (long*)malloc((N*N)*sizeof(long));
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            matrix[i*N+j] = i+j;
        }
    }
}

int main(int argc, const char * argv[]) {
   
    
    RR a, b, c;
    
    
    char filename[10], number[1014];
    double starTime, endTime;
    int i, j, n;
    
    //int base[]= {40,  66,  100, 134, 166, 198,  -1,  -1,  -1,  -1};
    int dim[] = {80, 120, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    
    for(i=0; i<10; i++){
    
        n = dim[i];
        a.SetPrecision(n);
        a.SetOutputPrecision(n);
        b.SetPrecision(n);
        b.SetOutputPrecision(n);
        c.SetPrecision(n);
        c.SetOutputPrecision(n);
        
        sprintf(filename, "%df.txt", dim[i]);
        FILE *file = fopen(filename, "r");
        
        if(file){
            cout << "********* Precision " << n << " *********\n";
            fgets(number, 1024, file);
            a = conv<RR>(number);
            
            fgets(number, 1024, file);
            b = conv<RR>(number);
            
            
            /*************************
             ***      Addition     ***
             *************************/
            cout << "Addition\n";
            for (j=0; j<NUM_REP; j++) {
                
                cleanCache();
                GET_TIME(starTime);
                add(c, a, b);
                GET_TIME(endTime);
                
                cout << endTime-starTime << "\n";
            }
            cout << endl;
            
            /*************************
             ***    Subtraction    ***
             *************************/
            
            cout << "Subtraction\n";
            for (j=0; j<NUM_REP; j++) {
                
                cleanCache();
                GET_TIME(starTime);
                sub(c, a, b);
                GET_TIME(endTime);
                
                cout << endTime-starTime << "\n";
            }
            cout << endl;
            
            /*************************
             ***   Multiplication  ***
             *************************/
            
            cout << "Multiplication\n";
            for (j=0; j<NUM_REP; j++) {
                
                cleanCache();
                GET_TIME(starTime);
                mul(c, a, b);
                GET_TIME(endTime);
                
                cout << endTime-starTime << "\n";
            }
            cout << endl;
            
            /**************************
             ***      Division      ***
             **************************/
            
            cout << "Division\n";
            for (j=0; j<NUM_REP; j++) {
                
                cleanCache();
                GET_TIME(starTime);
                div(c, a, b);
                GET_TIME(endTime);
                
                cout << endTime-starTime << "\n";
            }
            cout << endl;
            
            
            /**************************
             ***    ACC Addition    ***
             **************************/
            cout << "ACC Addition\n";
            for (j=0; j<NUM_REP; j++) {
                
                cleanCache();
                GET_TIME(starTime);
                add(a, a, b);
                GET_TIME(endTime);
                
                cout << endTime-starTime << "\n";
            }
            cout << endl;
            
            /**************************
             ***  ACC Subtraction   ***
             **************************/
            
            cout << "ACC Subtraction\n";
            for (j=0; j<NUM_REP; j++) {
                
                cleanCache();
                GET_TIME(starTime);
                sub(a, a, b);
                GET_TIME(endTime);
                
                cout << endTime-starTime << "\n";
            }
            cout << endl;
            
            /**************************
             *** ACC Multiplication ***
             **************************/
            
            cout << "ACC Multiplication\n";
            for (j=0; j<NUM_REP; j++) {
                
                cleanCache();
                GET_TIME(starTime);
                mul(a, a, b);
                GET_TIME(endTime);
                
                cout << endTime-starTime << "\n";
            }
            cout << endl;
            
            /*************************
             ***   ACC Division    ***
             *************************/
            
            cout << "ACC Division\n";
            for (j=0; j<NUM_REP; j++) {
                
                cleanCache();
                GET_TIME(starTime);
                div(a, a, b);
                GET_TIME(endTime);
                
                cout << endTime-starTime << "\n";
            }
            cout << endl;
            
            
            /*************************
             ***      SQ Root      ***
             *************************/
            
            cout << "SQ Root\n";
            for (j=0; j<NUM_REP; j++) {
                
                cleanCache();
                GET_TIME(starTime);
                SqrRoot(c, b);
                GET_TIME(endTime);
                
                cout << endTime-starTime << "\n";
            }
            cout << endl;
            
            
            /*************************
             ***     Power x^2     ***
             *************************/
            
            cout << "Power x^2\n";
            for (j=0; j<NUM_REP; j++) {
                
                cleanCache();
                GET_TIME(starTime);
                sqr(c, a);
                GET_TIME(endTime);
                
                cout << endTime-starTime << "\n";
            }
            cout << endl;
            
            /*************************
             ***     Power x^y     ***
             *************************/
            
            cout << "Power x^y\n";
            for (j=0; j<NUM_REP; j++) {
                
                cleanCache();
                GET_TIME(starTime);
                pow(c, a, b);
                GET_TIME(endTime);
                
                cout << endTime-starTime << "\n";
            }
            cout << endl;
            
            
            
        } else
            cout << "File '"<< filename << "' do not exist!\n";
        
    }
    
    return 1;
}
















