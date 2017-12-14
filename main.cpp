#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <boost/iterator/zip_iterator.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/tuple/tuple.hpp>

template<class... Conts>
auto zip_range(Conts&&... conts)
{
  return boost::make_iterator_range(boost::make_zip_iterator(boost::make_tuple(conts.begin()...)),
                                    boost::make_zip_iterator(boost::make_tuple(conts.end()...)));
}

int main ()
{
    std::vector<std::string> v1{ "jeden", "dwa", "trzy", "cztery" };
    std::vector<std::string> v2{ "one", "two", "three", "four" };
    for(auto&& t : zip_range(v1, v2))
      std::cout << t.get<0>() << " : " << t.get<1>() << "\n";
    return 0;
}
