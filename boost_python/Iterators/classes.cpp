#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <boost/python/extract.hpp>

class Example{
public:
    Example(){

    }

   void add(const std::string& s){
       value_.push_back(s);
   }

   std::vector<std::string>::iterator begin(){
       return value_.begin();
   }

   std::vector<std::string>::iterator end(){
       return value_.end();
   }

private:
    std::vector<std::string> value_;
};

using namespace boost::python;

BOOST_PYTHON_MODULE(classes){
    class_<Example>("Example")
        .def("strings", range(&Example::begin, &Example::end))
        .def("add", &Example::add)
    ;

}