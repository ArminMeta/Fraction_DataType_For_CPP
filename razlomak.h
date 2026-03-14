#include <iostream>
#include <string>

using namespace std;

class razlomak{
    int brojnik;
    int nazivnik;

    public:
        razlomak(int B=0, int N=0): brojnik(B), nazivnik(N) { }

        //------------ Posebne Funkcije ------------
        int nzd(int a, int b);
        razlomak skracen();

        //------------ I / O ------------
        friend ostream& operator<<(ostream &cout, const razlomak &r);
        friend istream& operator>>(istream &cin, razlomak &r);

        //------------ Poredjenja ------------
        friend bool operator==(const razlomak&, const razlomak&);
        friend bool operator!=(const razlomak&, const razlomak&);
        friend bool operator>(const razlomak&, const razlomak&);
        friend bool operator>=(const razlomak&, const razlomak&);
        friend bool operator<=(const razlomak&, const razlomak&);
        friend bool operator<(const razlomak&, const razlomak&);

        //------------ Osnovne Operacije ------------
        friend razlomak operator+(const razlomak&, const razlomak&);
        friend razlomak operator-(const razlomak&, const razlomak&);
        friend razlomak operator/(const razlomak&, const razlomak&);
        friend razlomak operator*(const razlomak&, const razlomak&);

        //------------ Dodjele | Samododjele ------------
        razlomak &operator=(const razlomak&);
        razlomak &operator+=(const razlomak&);
        razlomak &operator-=(const razlomak&);
        razlomak &operator*=(const razlomak&);
        razlomak &operator/=(const razlomak&);

        //------------ pomjeranja ------------
        friend razlomak &operator++(razlomak &, int);
        friend razlomak &operator--(razlomak &, int);


};
int razlomak::nzd(int a, int b){
    while(b!=0){
        int t=b;
        b= a%b;
        a = t;
    }
    return a;   
}
razlomak razlomak::skracen(){
    int n= nzd(brojnik, nazivnik);
    return razlomak(brojnik/n, nazivnik/n);
}

istream& operator>>(istream &cin, razlomak &r){
    char znak;
    cin >> r.brojnik >> znak >> r.nazivnik;
    razlomak temp(r.brojnik, r.nazivnik);
    r.skracen();
    if(r.nazivnik == 0){
        throw invalid_argument("Nazivnik ne moze biti nula");
    }
    return cin;
}
ostream& operator<<(ostream &cout, const razlomak &r){
    cout << r.brojnik << " | " << r.nazivnik << endl;
    return cout;
}

bool operator==(const razlomak &a, const razlomak &b){
    return a.brojnik == b.brojnik && a.nazivnik == b.nazivnik;
}
bool operator!=(const razlomak &a, const razlomak &b){
    return !(a==b);
}
bool operator>(const razlomak &a, const razlomak &b){
    return float(a.brojnik/float(a.nazivnik))>float(b.brojnik/float(b.nazivnik));
}
bool operator>=(const razlomak &a, const razlomak &b){
    return float(a.brojnik/float(a.nazivnik))>=float(b.brojnik/float(b.nazivnik));
}
bool operator<(const razlomak &a, const razlomak &b){
    return float(a.brojnik/float(a.nazivnik))<float(b.brojnik/float(b.nazivnik));
}
bool operator<=(const razlomak &a, const razlomak &b){
    return float(a.brojnik/float(a.nazivnik))<=float(b.brojnik/float(b.nazivnik));
}

razlomak operator+(const razlomak &a, const razlomak &b){
    if(a.nazivnik == b.nazivnik){
        return razlomak(a.brojnik+b.brojnik, a.nazivnik);
    }else{
        return razlomak(a.brojnik*b.nazivnik + b.brojnik*a.nazivnik, a.nazivnik * b.nazivnik).skracen();
    }
}
razlomak operator-(const razlomak &a, const razlomak &b){
    if(a.nazivnik == b.nazivnik){
        return razlomak(a.brojnik-b.brojnik, a.nazivnik);
    }else{
        return razlomak(a.brojnik*b.nazivnik - b.brojnik*a.nazivnik, a.nazivnik * b.nazivnik).skracen();
    }
}
razlomak operator*(const razlomak &a, const razlomak &b){
    return razlomak(a.brojnik*b.brojnik,a.nazivnik*b.nazivnik).skracen();
}
razlomak operator/(const razlomak &a, const razlomak &b){
    if(a.brojnik%b.brojnik == 0 && a.nazivnik%b.nazivnik==0)
        return razlomak(a.brojnik/b.brojnik, a.nazivnik/b.nazivnik);
    else
        return razlomak(a.brojnik*b.nazivnik, a.nazivnik*b.brojnik).skracen();
}

razlomak &razlomak::operator=(const razlomak &r){
    brojnik = r.brojnik;
    nazivnik = r.nazivnik;

    return *this;
}
razlomak &razlomak::operator+=(const razlomak &a){
    if(nazivnik == a.nazivnik){
        brojnik = brojnik+a.brojnik;
        nazivnik = nazivnik;
        return *this;
    }else{
        brojnik = brojnik*a.nazivnik + a.brojnik*nazivnik;
        nazivnik = nazivnik * a.nazivnik;
        *this = this->skracen();
        return *this;
    }
}
razlomak &razlomak::operator-=(const razlomak &a){
    if(nazivnik == a.nazivnik){
        brojnik = brojnik-a.brojnik;
        nazivnik = nazivnik;
        return *this;
    }else{
        brojnik = brojnik*a.nazivnik - a.brojnik*nazivnik;
        nazivnik = nazivnik * a.nazivnik;
        *this = this->skracen();
        return *this;
    }
}
razlomak &razlomak::operator*=(const razlomak &a){
    brojnik = brojnik * a.brojnik;
    nazivnik = nazivnik * a.nazivnik;
    *this = this->skracen();
    return *this;
}
razlomak &razlomak::operator/=(const razlomak &a){
    if(brojnik%a.brojnik == 0 && nazivnik%a.nazivnik==0){
        brojnik = brojnik/a.brojnik;
        nazivnik = nazivnik/a.nazivnik;
        return *this;
    }
    else{
        brojnik = brojnik * a.nazivnik;
        nazivnik = nazivnik * a.brojnik;
        *this = this->skracen();
        return *this;
    }
    
}

razlomak &operator++(razlomak &r, int){
    razlomak temp(r.brojnik, r.nazivnik);
    r.brojnik += r.nazivnik;
    return r;
}
razlomak &operator--(razlomak &r, int){
    razlomak temp(r.brojnik, r.nazivnik);
    r.brojnik -= r.nazivnik;
    return r;
}