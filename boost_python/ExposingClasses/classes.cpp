#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <boost/python/extract.hpp>
#include <string>
#include <sstream>
#include <vector>

class TestClass{
public:
    TestClass(std::string msg) : msg_(msg){

    }

    void set(std::string msg){
        msg_ = msg;
    }

    void many(boost::python::list msgs){
        size_t l = len(msgs);
        std::stringstream ss;
        for(size_t i = 0; i < l; i++){
            if(i > 0){
                ss << ", ";
            }
            std::string s = boost::python::extract<std::string> (msgs[i]);
            ss << s;
        }
        msg_ = ss.str();
    }
    
    std::string greet(){
        return msg_;
    }

    double getValue() const{
        return value_;
    }
    double setValue(double v){
        value_ = v;
    }

    std::string name_;

private:
    std::string msg_;
    double value_;
};

using namespace boost::python;

BOOST_PYTHON_MODULE(classes){
    class_<TestClass>("TestClass", init<std::string>())
        .def("greet", &TestClass::greet)
        .def("set", &TestClass::set)
        .def("many", &TestClass::many)
        .def_readwrite("name", &TestClass::name_)
        .add_property("value", &TestClass::getValue, &TestClass::setValue)
    ;
}