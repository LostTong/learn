#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <boost/python/extract.hpp>

class NumberLike{
public:
    NumberLike(int n = 0): v_(n){

    }

    NumberLike& operator += (int i){
        v_ += i;
        return *this;
    }

    std::string str() const{
        std::stringstream s;
        s << v_;
        return s.str();
    }

    std::string repr() const{
        std::stringstream s;
        s << "NumberLike(" << v_ << ")";
        return s.str();
    }

private:
    int v_;
};

NumberLike operator + (NumberLike n, int i){
    n += i;
    return n;
}

using namespace boost::python;

BOOST_PYTHON_MODULE(classes){
    class_<NumberLike>("NumberLike")
        .def(init< optional<int> >())
        .def(self + int())
        .def("__str__", &NumberLike::str)
        .def("__repr__", &NumberLike::repr)
    ;

}