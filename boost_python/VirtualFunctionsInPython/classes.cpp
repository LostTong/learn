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
};

void identity(Base *b){
    std::cout << b->name() << " called." << std::endl;
}


using namespace boost::python;

class BaseWrap: public Base, public wrapper<Base>{
public:
    virtual std::string name() const {
        if(override n = this->get_override("name")){
            return n();
        }
        return Base::name();
    }

    std::string default_name() const{
        std::cout << "default_name" << std::endl;
        return this->Base::name();
    }
};

BOOST_PYTHON_MODULE(classes){
    class_<BaseWrap, boost::noncopyable>("Base")
        .def("name", &Base::name, &BaseWrap::default_name)
    ;

    def("identity", identity);
}