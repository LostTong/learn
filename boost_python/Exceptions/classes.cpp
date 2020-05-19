#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <boost/python/extract.hpp>

struct TestException{

};

void translateException(const TestException &x){
    PyErr_SetString(PyExc_UserWarning, "Test Exception...");
}

void func(){
    throw TestException();
}

using namespace boost::python;

BOOST_PYTHON_MODULE(classes){
    register_exception_translator<TestException>(translateException);
    
    def("func", &func);
}