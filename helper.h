#include <string>

using namespace std;

template <class T>
inline void debug(string comment, T data) {
	cout << "[DEBUG!] " << comment << " : " << data << endl;
}

inline void trace(string comment) {
	cout << "[TRACE!] " << comment << endl;
}

inline void todo(string comment) {
    cout << "[TODO!!] " << comment << endl;
}
