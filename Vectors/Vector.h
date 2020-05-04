#include <iostream>
using namespace std;

class Vector{
    int cs;
    int ms;
    int *arr;

    public:

    Vector(){
        cs = 0;
        ms = 1; //total size
        arr = new int[ms];
    }

    void push_back(int key){
        if(cs == ms){
            ms = ms*2;
            int *old = arr;
            arr = new int[ms];
            for(int i=0; i<cs; i++){
                arr[i] = old[i];
            }
            delete [] old;
        }
        arr[cs] = key;
        cs++;
    }
    void pop_back(){
        cs--;
    }
    int front(){
        return arr[0];
    }
    int back(){
        return arr[cs-1];
    }
    bool empty(){
        return cs == 0;
    }
    int capacity(){
        return ms;
    }
    int size(){
        return cs;
    }
    //Operator overloading
    int operator[] (int i){
        return arr[i];
    }

};