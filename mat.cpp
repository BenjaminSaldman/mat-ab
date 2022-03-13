#include <string>
#include "mat.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
const int Invalid=33;
const int Invalid2=127;
/**
*Checking the validity of the char: checks if it not special char or above 127 or below 33.
*/
bool checkValid(char a){
    int check=0;
    if(a=='\n' || a=='\t' || a==' '|| a=='\r'){
        check=1;
    }
    if(a<Invalid)
    {
        check=1;
    }
    if(a>=Invalid2)
    {
        check=1;
    }
    return check==0;
}
/**
* converting the mat to string.
*/
string copyMat(vector<vector<char>>arr, int colmn, int row){
    string ans;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<colmn;j++)
        {
            ans+=arr[i][j];
        }
        ans+='\n';
    }
    return ans;

}
namespace ariel{
/**
* very simple algorithm: create 2d array (used vector because dynamic array didn't work with tidy), than generate the
* number of layers in the mat: min between width or height /2 +1 because in every layer the height and the width decrease by 2.
* Then start to run from i=0 to layers number: in each iteration, the row number is width-i and the height is height-i.
* In the inner loop we start to fill every layer of the mat: first the width: fill mat in [i][j] and [height-i-1][j] where j is 
* number that running from i to width-i and height-i-1 is the simetric index of the width.
* similary, we fill the height: fill mat in [j][i] and [j][width-i-1] where j  is the number running from i to height-i 
* and width-i-1 is the simetric index of the height.
* Then we copy every row of the matrix to the string (with '\n') we want to return and return it.
*/
string mat(int colmn, int row, char c1, char c2){
    if(!checkValid(c1) || !checkValid(c2) || row%2==0 || colmn%2==0 || row<=0 || colmn<=0){
        throw invalid_argument{"Invalid arguments!"};
    }
    string ans;
    

    // char** arr=new char*[row];
    // for(int i=0;i<row;i++){
    //     arr[i]=new char[colmn];
    // }
    vector<vector<char>>arr(row,vector<char>(colmn)); //wanted to use matrix, clang tidy told me to use vector...
    char currChar=c1;
    int layers = row<colmn? row:colmn; //number of layers of the mat, this number is the minimum between the col,row /2 +1.
    layers/=2;
    layers++;
    //filling the mat.
    for(int i=0;i<layers;i++)
    {
        //first we fill the columns, we fill the current column and the simetric one.
        for(int j=i;j<colmn-i;j++)
        {
            arr[i][j]=currChar;
        }
        for (int j=i;j<colmn-i;j++)
        {
            arr[row-i-1][j]=currChar;
        }
        //then we fill the rows, first we fill the first row and then the simetric one
        for(int j=i;j<row-i;j++)
        {
           arr[j][i]=currChar;
           
        }
        for(int j=i;j<row-i;j++)
        {
            arr[j][colmn-i-1]=currChar;
        }
        //chenging the symbol.
        if(currChar==c1){
            currChar=c2;
        }
        else{
        currChar=c1;
        }
    }
   
    return copyMat(arr,colmn,row);
}
};