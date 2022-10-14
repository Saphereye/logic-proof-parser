#include <string>

using namespace std;

inline void trace(string comment) {
	cout << "[TRACE!] " << comment << endl;
}

template <class T>
inline void debug(string comment, T data) {
	cout << "[DEBUG!] " << comment << " : " << data << endl;
}