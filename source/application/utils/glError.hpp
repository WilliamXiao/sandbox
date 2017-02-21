#ifndef GLERROR_HPP
#define GLERROR_HPP

// Ask Opengl for errors:
// Result is printed on the standard output
// usage :
//      glCheckError(__FILE__,__LINE__);
void glCheckError(const char* file, unsigned int line);

#endif /* end of GLERROR_HPP */

