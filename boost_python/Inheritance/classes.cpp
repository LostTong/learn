#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <boost/python/extract.hpp>

class Base{
public:
    virtual std::string name() const {
        return "Base";
    }


    virtual ~Base(){

    }

    int getValue(){
        return value_;
    }

    void setValue(int v){
        value_ = v;
    }

    int value_;
};

class Derived : public Base{
public:
    virtual std::string name() const {
        return "Derived";
    }

    int value2;
};

void fb(Base *b){
    std::cout << b->name() << " called." << std::endl;
}

void fd(Derived *d){
    std::cout << "Derived " << d->name() << " called." << std::endl;
}

Base* factory(){
    return new Derived();
}



using namespace boost::python;

BOOST_PYTHON_MODULE(classes){
    class_<Base, boost::noncopyable>("Base")
        .def("name", &Base::name)
    ;

    class_<Derived, bases<Base> >("Derived")
        .add_property("value", &Derived::getValue, &Derived::setValue)
        .def_readwrite("value2", &Derived::value2)
    ;

    def("fb", fb);
    def("fd", fd);
    def("factory", factory, return_value_policy<manage_new_object>());
}