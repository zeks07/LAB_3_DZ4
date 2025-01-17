
#ifndef MAIN_CPP_MEC_H
#define MAIN_CPP_MEC_H
#include "Par.h"

class Mec {

private:

    Par<Tim*> par_timova;
    Par<int> par_poena;
    enum stanje{POBEDA_DOMACIN, NERESENO, POBEDA_GOST};
    stanje ishod;

protected:

    virtual void pisi(ostream&os){
        os<<par_timova<<endl;
        if(proveriDaLiJeOdigranMec()){
            os<<ishod<<endl;
        }
    }

public:

    Mec(Tim* tim_domacin, Tim* tim_gost){
        par_timova.postaviPod1(tim_domacin);
        par_timova.postaviPod2(tim_gost);
    }

    void odigrajMec();

    bool proveriDaLiJeOdigranMec(){
        if(this->ishod==POBEDA_DOMACIN || this->ishod==NERESENO || this->ishod==POBEDA_GOST){
            return true;
        }else{
            return false;
        }
    }

    Par<int> dohvParPoena(){
        return this->par_poena;
    }

    friend ostream& operator << (ostream& os, Mec & m){
        m.pisi(os);
        return os;
    }

};


#endif //MAIN_CPP_MEC_H
