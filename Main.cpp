#include <iostream>
#include <string>
#include <stdexcept>
#include "mat.hpp"
using namespace std;
using namespace ariel;
int main(){
    cout<<mat(51,49,'@','#')<<endl;
    cout<<mat(9,7,'$','*')<<endl;
    try{
        cout<<mat(200,5,'^','*');
    }catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl; 
    }
}

    