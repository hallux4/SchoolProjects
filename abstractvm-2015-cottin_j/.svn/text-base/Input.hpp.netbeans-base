/* 
 * File:   Input.hpp
 * Author: cottin_j
 *
 * Created on February 8, 2012, 6:33 PM
 */

#ifndef INPUT_HPP
#define	INPUT_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <limits>
#include <limits.h>
#include <float.h>

#include "error.hpp"

class Input {
public:

    Input();
    ~Input();
    
    std::list<std::string> lexing(std::string & data);
    //DEBUG affichage list for_each via i_print_elem
    void operator()(std::string const & elem) const;
    void i_print_elem() const;

private:
    std::vector<std::string> to_comp;
    std::vector<std::string> to_type;
    std::list<std::string> lexem_list;
    
    void fill_vector_comp();
    void fill_vector_type();
    void clean_it(std::string & data, std::string & data_clean);
    bool scan_value(std::string & lexem);
    int compare(std::string & lexem);
    void s_print_elem(std::string const & elem);
};

#endif	/* INPUT_HPP */

