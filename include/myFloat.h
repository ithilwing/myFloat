#ifndef MYFLOAT_H
#define MYFLOAT_H

const double EPS = 1E-9;


class myFloat
{
    public:
        myFloat() {} //
        myFloat(const float& new_float); //

        myFloat& operator= (const myFloat& another);
;
        float getValue() const; //
        void setValue(const myFloat& another); //
        void setValue(const float& another); //

        myFloat operator+ () const; //
        myFloat operator- () const; //

        myFloat operator += (const myFloat& another); //
        myFloat operator -= (const myFloat& another); //
        myFloat operator *= (const myFloat& another); //
        myFloat operator /= (const myFloat& another); //

        bool operator== (const myFloat& another) const; //
        bool operator!= (const myFloat& another) const; //

        bool operator> (const myFloat& another) const;
        bool operator>= (const myFloat& another) const;
        bool operator< (const myFloat& another) const;
        bool operator<= (const myFloat& another) const;


    protected:

    private:
        float value;
};

myFloat operator+ (const myFloat& a, const myFloat& b); //

myFloat operator- (const myFloat& a, const myFloat& b); //

myFloat operator* (const myFloat& a, const myFloat& b); //

myFloat operator/ (const myFloat& a, const myFloat& b); //


myFloat::myFloat(const float& new_float) {
    setValue(new_float);
}

myFloat& myFloat::operator=(const myFloat& another) {
        if (this == &another) {
            return *this;
        }
        value = another.value;
        return *this;
}

float myFloat::getValue() const {
    return value;
}

void myFloat::setValue(const myFloat& another) {
    value = another.value;
}

void myFloat::setValue(const float& another) {
    value = another;
}

myFloat myFloat::operator+ () const { //unary
    return *this;
}

myFloat myFloat::operator- () const { //unary
    float a = -1.0;
    return myFloat(a*value);
}

myFloat myFloat::operator+= (const myFloat& another) {
    setValue(value+another.value);
    return *this;
}

myFloat myFloat::operator-= (const myFloat& another) {
    setValue(value-another.value);
    return *this;
}

myFloat myFloat::operator*= (const myFloat& a){
    setValue(value*a.value);
    return *this;
}

myFloat myFloat::operator/= (const myFloat& a){
    setValue(value/a.value);
    return *this;
}

myFloat operator+ (const myFloat& a, const myFloat& b){ //binary
    myFloat tmp = a;
    return tmp+=b;
}

myFloat operator- (const myFloat& a, const myFloat& b){ //binary
    myFloat tmp = a;
    return tmp-=b;
}

myFloat operator* (const myFloat& a, const myFloat& b){ //binary
    myFloat tmp = a;
    return tmp*=b;
}


myFloat operator/ (const myFloat& a, const myFloat& b){ //binary
    myFloat tmp = a;
    return tmp/=b;
}

bool myFloat::operator== (const myFloat& another) const {
    return (std::abs(another.value-value)<EPS);
}

bool myFloat::operator!= (const myFloat& another) const {
    return !(*this == another);
}

bool myFloat::operator> (const myFloat& another) const {
    return (value>another.value);
}

bool myFloat::operator< (const myFloat& another) const {
    return (value<another.value);
}

bool myFloat::operator>= (const myFloat& another) const {
    return (value>another.value || std::abs(value-another.value)<EPS);
}

bool myFloat::operator<= (const myFloat& another) const {
    return (value<another.value || std::abs(value-another.value)<EPS);
}

#endif // MYFLOAT_H
