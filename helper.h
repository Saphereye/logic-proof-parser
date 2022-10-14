#include <string>

using namespace std;

/**
 * @brief Prints debug info
 * 
 * @tparam T 
 * @param comment 
 * @param data 
 */
template <typename T>
inline void debug(string comment, T data) {
	cout << "[DEBUG!] " << comment << " : " << data << endl;
}

/**
 * @brief Prints out comments/trace info
 * 
 * @param comment 
 */
inline void trace(string comment) {
	cout << "[TRACE!]" << " : " <<  comment << endl;
}

/**
 * @brief Prints out any todo comments
 * 
 * @param comment 
 */
inline void todo(string comment) {
    cout << "[TODO!!]" << " : " <<  comment << endl;
}
