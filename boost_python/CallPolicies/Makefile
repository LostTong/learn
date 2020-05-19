object = classes
module = classes

$(module).so : $(object).o
	g++ -shared $(object).o -o $(module).so -lpython2.7 -lboost_python

$(object).o : $(object).cpp
	g++ -c -fPIC -I/usr/include/python2.7 $(object).cpp -o $(object).o