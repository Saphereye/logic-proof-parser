#include <string>

using namespace std;

bool isDebugMode = true;

/**
 * @brief Prints debug info
 * 
 * @tparam T 
 * @param comment 
 * @param data 
 */
template <typename T>
inline void debug(string comment, T data) {
	if (isDebugMode) cout << "[DEBUG!] " << comment << " : " << data << endl;
}

/**
 * @brief Prints out comments/trace info
 * 
 * @param comment 
 */
inline void trace(string comment) {
	if (isDebugMode) cout << "[TRACE!]" << " : " <<  comment << endl;
}

/**
 * @brief Prints out any todo comments
 * 
 * @param comment 
 */
inline void todo(string comment) {
    if (isDebugMode) cout << "[TODO!!]" << " : " <<  comment << endl;
}
