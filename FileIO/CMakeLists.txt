INCLUDE_DIRECTORIES(EMGgenerator)

ADD_LIBRARY(FileIO STATIC
  DataFromFile.cpp
  HeaderFile.cpp
   DataFromAngleFile.cpp
 )
