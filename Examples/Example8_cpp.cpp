/*
 * TextParser - Text Parsing Library
 *
 * Copyright (C) 2012-2014 Institute of Industrial Science, The University of Tokyo.
 * All rights reserved.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include "TextParser.h"

int main(int argc, char** argv){


  std::string filename;

  TextParser* tp=TextParser::get_instance_singleton();
  //すべてパースエラー
  filename = "tpp_examples/incorrect_range_1.tpp";
  TextParserError error = tp->read(filename);
  if(error!=TP_NO_ERROR) std::cout<< "tpp file parse error file="<<filename<<std::endl;

  filename = "tpp_examples/incorrect_range_2.tpp";
  error=tp->read(filename);
  if(error!=TP_NO_ERROR) std::cout<< "tpp file parse error file="<<filename<<std::endl;

  filename = "tpp_examples/incorrect_range_3.tpp";
  error=  tp->read(filename);
  if(error!=TP_NO_ERROR) std::cout<< "tpp file parse error file="<<filename<<std::endl;

  filename = "tpp_examples/incorrect_list_1.tpp";
  error=tp->read(filename);
  if(error!=TP_NO_ERROR) std::cout<< "tpp file parse error file="<<filename<<std::endl;


  return 0;
}
