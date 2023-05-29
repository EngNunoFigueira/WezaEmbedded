#include<iostream>
#include<set>
#include<string>
#include <vector>

const std::set<std::string>& getTrafficInterfaces(std::set<std::string>& setOfNumbers)
{
	//std::set<std::string>& setOfNumbers;
	setOfNumbers.insert("NUNO");
	setOfNumbers.insert("HELIO");
	setOfNumbers.insert("MAURO");
	setOfNumbers.insert("FILIPE");
	setOfNumbers.insert("ROBERTO");

   return setOfNumbers;
}

int main()
{
	std::set<std::string> newSetsOfNames;
	std::set<std::string> setOfNumbers;
 
	// Lets insert four elements
	setOfNumbers.insert("first");
	setOfNumbers.insert("second");
	setOfNumbers.insert("third");
	setOfNumbers.insert("first");
 
	// Only 3 elements will be inserted
	std::cout<<"Set Size = "<<setOfNumbers.size()<<std::endl;
 
	// Iterate through all the elements in a set and display the value.
	for (std::set<std::string>::iterator it=setOfNumbers.begin(); it!=setOfNumbers.end(); ++it)
	    std::cout << ' ' << *it;
	    std::cout<<"\n";
	
	 std::cout<<"SEGUNDA LISTA DE SETS\n";

    getTrafficInterfaces(newSetsOfNames);
    std::cout<<"The set size is: " <<getTrafficInterfaces(newSetsOfNames).size()<<std::endl;

    for(const auto& interface : getTrafficInterfaces(newSetsOfNames))
    	std::cout << ' ' << interface;
 
    std::cout<<"\n";

    std::cout<<"Satrting working with the vector " <<std::endl;
    std::vector<std::string> protocolSdListPort = {"Gx", "Rx", "Sd"};
    std::vector<std::string>::const_iterator iter = protocolSdListPort.begin();
    std::cout << "Adding port " << *iter << " to the sniffer filter " << std::endl;

    
    std::set<std::string> deleteDuplicatedPort;

    for( auto ports : iter)
    {
    	deleteDuplicatedPort.insert(*iter);
    }

	return 0;


}
