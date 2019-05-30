ADD_EXECUTABLE(TestBoostBSpline
	BSplineTest.cpp
)


target_link_libraries(TestBoostBSpline
	MTUSpline
	FileIO
	${WINLIB}
	${WINMM}
	${Boost_LIBRARIES}
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)



enable_testing()

add_test(NAME BsplineTest COMMAND $<TARGET_FILE:TestBoostBSpline>)
