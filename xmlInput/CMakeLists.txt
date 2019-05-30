ADD_LIBRARY(xmlInput STATIC
  NMSmodel.cxx
  execution.cxx
  ExecutionXmlReader.cpp
)
	
TARGET_LINK_LIBRARIES(xmlInput
	${XERCES_LIBRARY}
)
