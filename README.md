# CPSC301-Assignment-2
Kayla Nguyen
Purpose of program:

To understand that vectors are dynamically allocated arrays,
which means that they can be resized as needed rather than being of fixed size.
push_back may construct a temporary object which then will need to get moved into the vector v, whereas emplace_back
just forwards the argument and constructs it directly in place with no copies or moves needed.
