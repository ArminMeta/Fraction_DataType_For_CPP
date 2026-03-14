#include <iostream>
#include "razlomak.h"

using namespace std;

int main(){
    razlomak r1, r2;
    cout <<"Unesite dva vasa zalomka jedno ispod drugog u obliku x | b "<< endl;
    cin >> r1;
    cin >> r2;

    cout << "Prvi razlomak vam je: " << r1 << endl << "Drugi razlomak vam je: " << r2 << endl;
    //Poredjenja
    cout << "da li su ovi razlomci jednaki: ";
    if(r1==r2) cout <<"Jesu"<< endl;
    else cout <<"Nisu" << endl;
    cout << "Da li je prvi veci od drugog: ";

    if(r1>r2) cout <<"Da"<< endl;
    else cout <<"Ne" << endl;

    cout << "Da li je prvi manji od drugog: ";
    if(r1<=r2) cout <<"Da"<< endl;
    else cout <<"Ne" << endl;

    //operacije
    cout << "Zbir vasih razlomaka: " << r1+r2 << endl;
    cout << "Razlika vasih razlomaka: " << r1-r2 << endl;
    cout << "Proizvod vasih razlomaka: " << r1*r2 << endl;
    cout << "Kolicnik vasih razlomaka: " << r1/r2 << endl;

    //samododjela
    razlomak temp;
    temp = r1;
    r1+=r2;
    cout << "Prvi razlomak uvecan za Drugi: " << r1 << endl;
    r1 = temp;
    r1-=r2;
    cout << "Prvi razlomak umanjen za Drugi: " << r1 << endl;
    r1 = temp;
    r1*=r2;
    cout << "Prvi razlomak uvecan za puta drugog: " << r1 << endl;
    r1 = temp;
    r1/=r2;
    cout << "Prvi razlomak umanjen za puta drugog: " << r1 << endl;
    r1= temp;

    cout << "Prvi razlomak uvecan za jedan: " << r1++ << endl;
    cout << "Drugi razlomak umanjen za jedan: " << r2--;
    return 0;
}