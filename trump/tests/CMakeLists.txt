
# Timestamp
add_executable(timestamp_unittest timestamp_unittest.cc)
add_test(NAME timestamp_unittest COMMAND timestamp_unittest)
INSTALL(TARGETS timestamp_unittest RUNTIME DESTINATION time)

# Timestampp
add_executable(timestampp_unittest timestampp_unittest.cc)
add_test(NAME timestampp_unittest COMMAND timestampp_unittest)
INSTALL(TARGETS timestampp_unittest RUNTIME DESTINATION time)

# AtomicI
add_executable(atomic_unittest atomic_unittest.cc)
add_test(NAME atomic_unittest COMMAND atomic_unittest)
INSTALL(TARGETS atomic_unittest RUNTIME DESTINATION common)

# Exception 
add_executable(exception_unittest exception_unittest.cc)
add_test(NAME exception_unittest COMMAND exception_unittest)
INSTALL(TARGETS exception_unittest RUNTIME DESTINATION common)
