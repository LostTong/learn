#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <boost/python/extract.hpp>

class Example{
    Example(std::string n): name_(n){

    }
    std::string name_;

public:
    std::string name() const {
        return name_;
    }

    static Example* factory(){
        return new Example("factory");
    }

    static Example* singleton(){
        static Example instance = Example("singleton");
        return &instance;
    }

};

using namespace boost::python;

BOOST_PYTHON_MODULE(classes){
    class_<Example>("Example", no_init)
        .def("__str__", &Example::name)
        .def("factory", &Example::factory, return_value_policy<manage_new_object>())
        .staticmethod("factory")
        .def("singleton", &Example::singleton, return_value_policy<reference_existing_object>())
        .staticmethod("singleton")
    ;

}