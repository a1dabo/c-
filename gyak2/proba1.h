#ifndef PROBA1_H
#define PROBA1_H



template <typename T>
class proba1
{
private:
    T* a;/* data */
    T rea;
public:
    proba1(T& a)
    {
        this->rea=a;       //értéket ment referánciánál
        this->a=&a;        //elmenti a cimét
    }

    int get()
    {
        return *this->a;
    }

    void rew()
    {
        *this->a=this->rea;
    }

};




#endif